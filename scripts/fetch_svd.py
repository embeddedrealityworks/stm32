#!/usr/bin/env python3
"""
Download STM32 SVD files from ST's CAD selector API.

Usage:
    python fetch_svd.py [--out-dir DIR] [--filter PATTERN] [--dry-run]

Examples:
    python fetch_svd.py                          # download all SVDs to ./svd/
    python fetch_svd.py --filter STM32F4         # only STM32F4xx families
    python fetch_svd.py --out-dir /tmp/svd --dry-run
"""

import argparse
import fnmatch
import json
import subprocess
import sys
import zipfile
from pathlib import Path

# Constants

SELECTOR_URL = (
    "https://www.st.com/bin/st/selectors/cxst/en.cxst-cad-grid.html"
    "/CL1734.cad_models_and_symbols.svd.json"
)

DOWNLOAD_BASE = "https://www.st.com"

# Headers sent with every request via curl
HEADERS = {
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
    "Accept-Encoding": "identity",
    "Accept-Language": "en-GB,en;q=0.9",
    "Host": "www.st.com",
    "Sec-Fetch-Dest": "document",
    "Sec-Fetch-Mode": "navigate",
    "Sec-Fetch-Site": "none",
    "User-Agent": (
        "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) "
        "AppleWebKit/605.1.15 (KHTML, like Gecko) "
        "Version/17.2 Safari/605.1.15"
    ),
    "Connection": "keep-alive",
}

CURL_TIMEOUT = 60


# curl helpers

def _header_args() -> list[str]:
    args = []
    for k, v in HEADERS.items():
        args += ["-H", f"{k}: {v}"]
    return args


def curl_fetch(url: str) -> bytes:
    """Fetch URL via curl, return raw bytes. Raises on non-zero exit."""
    cmd = ["curl", "-L", "-s", "--max-time", str(CURL_TIMEOUT), "-o", "-", url] + _header_args()
    result = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if result.returncode != 0:
        raise RuntimeError(
            f"curl failed (exit {result.returncode}): {result.stderr.decode(errors='replace')}"
        )
    return result.stdout


def curl_download(url: str, dest: Path) -> None:
    """Download URL to dest file via curl. Raises on non-zero exit."""
    cmd = ["curl", "-L", "-s", "--max-time", str(CURL_TIMEOUT), "-o", str(dest), url] + _header_args()
    result = subprocess.run(cmd, stderr=subprocess.PIPE)
    if result.returncode != 0:
        raise RuntimeError(
            f"curl failed (exit {result.returncode}): {result.stderr.decode(errors='replace')}"
        )


# Parsing

def parse_rows(raw_json: str) -> list[dict]:
    """
    Parse ST's selector JSON into a list of family entries.

    JSON shape:
    {
      "rows": [
        {
          "localizedDescriptions": {"en": "STM32F4 series ..."},
          "localizedLinks":        {"en": "/resource/en/svd/stm32f4.zip"},
          "version": "1.2"
        },
        ...
      ]
    }

    Returns list of {"family": str, "version": str, "url": str}.
    """
    data = json.loads(raw_json)
    rows = data.get("rows", [])
    entries = []
    for row in rows:
        desc = row.get("localizedDescriptions", {}).get("en", "")
        link = row.get("localizedLinks", {}).get("en", "")
        version = row.get("version", "")
        family = desc.split()[0] if desc.strip() else ""
        if family and link:
            url = link if link.startswith("http") else DOWNLOAD_BASE + link
            entries.append({"family": family, "version": version, "url": url})
    return entries


# Downloading & extraction

def extract_svds(zip_path: Path, out_dir: Path) -> int:
    """Extract .svd files from zip into out_dir, normalising line endings. Returns count."""
    count = 0
    with zipfile.ZipFile(zip_path) as zf:
        for member in zf.namelist():
            if not member.lower().endswith(".svd"):
                continue
            dest = out_dir / Path(member).name
            with zf.open(member) as src, dest.open("w", encoding="utf-8") as dst:
                for line in src.read().decode("utf-8", errors="ignore").splitlines():
                    dst.write(line.rstrip() + "\n")
            count += 1
    return count


def download_family(entry: dict, raw_dir: Path, out_dir: Path, dry_run: bool) -> bool:
    """Download and extract one family zip. Returns True on success."""
    family = entry["family"]
    url = entry["url"]
    zip_name = url.rstrip("/").split("/")[-1]
    zip_path = raw_dir / zip_name

    print(f"  {family} v{entry['version']}: {zip_name}", end="")

    if dry_run:
        print(f"  [dry-run] {url}")
        return True

    if not zip_path.exists():
        print(" downloading...", end=" ", flush=True)
        try:
            curl_download(url, zip_path)
        except RuntimeError as exc:
            print(f"FAILED ({exc})")
            return False
    else:
        print(" (cached)", end=" ", flush=True)

    try:
        n = extract_svds(zip_path, out_dir)
        print(f"ok ({n} SVD{'s' if n != 1 else ''})")
        return True
    except (zipfile.BadZipFile, Exception) as exc:
        print(f"FAILED extracting ({exc})")
        return False


# CLI

def main():
    parser = argparse.ArgumentParser(
        description="Download STM32 SVD files from ST's selector API."
    )
    parser.add_argument(
        "--out-dir", default="svd", metavar="DIR",
        help="Directory to write extracted SVD files into (default: ./svd)",
    )
    parser.add_argument(
        "--raw-dir", default="svd/raw", metavar="DIR",
        help="Directory to cache downloaded zip files (default: ./svd/raw)",
    )
    parser.add_argument(
        "--filter", default="*", metavar="PATTERN",
        help="Glob pattern to match family names, e.g. 'STM32F4*' (default: *)",
    )
    parser.add_argument(
        "--dry-run", action="store_true",
        help="Print what would be downloaded without actually downloading",
    )
    parser.add_argument(
        "--selector-url", default=SELECTOR_URL, metavar="URL",
        help="Override the ST selector JSON URL",
    )
    parser.add_argument(
        "--dump-json", metavar="FILE",
        help="Save the raw selector JSON to FILE for inspection",
    )
    args = parser.parse_args()

    out_dir = Path(args.out_dir)
    raw_dir = Path(args.raw_dir)

    if not args.dry_run:
        out_dir.mkdir(parents=True, exist_ok=True)
        raw_dir.mkdir(parents=True, exist_ok=True)

    # 1. Fetch selector JSON
    print("Fetching selector JSON from ST...")
    try:
        raw = curl_fetch(args.selector_url).decode("utf-8", errors="ignore")
    except RuntimeError as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        sys.exit(1)

    if args.dump_json:
        Path(args.dump_json).write_text(raw)
        print(f"Raw JSON saved to {args.dump_json}")

    # 2. Parse
    entries = parse_rows(raw)
    if not entries:
        print("No entries found in JSON. Use --dump-json to inspect the response.")
        sys.exit(1)

    # 3. Filter
    pattern = args.filter.upper()
    filtered = [e for e in entries if fnmatch.fnmatch(e["family"].upper(), pattern)]
    print(f"Found {len(entries)} families, {len(filtered)} match '{args.filter}'")

    # 4. Download
    ok = fail = 0
    for entry in sorted(filtered, key=lambda e: e["family"]):
        if download_family(entry, raw_dir, out_dir, args.dry_run):
            ok += 1
        else:
            fail += 1

    print(f"\nDone: {ok} ok, {fail} failed" + (" (dry-run)" if args.dry_run else ""))
    if fail:
        sys.exit(1)


if __name__ == "__main__":
    main()
