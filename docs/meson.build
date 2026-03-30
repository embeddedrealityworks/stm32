asciidoc = find_program('asciidoctor', required: false)

alldocs = []

if asciidoc.found()
    adoc_files = files('index.adoc')

    alldocs += custom_target(
        'adocs',
        command: [
            asciidoc,
            '-b',
            'html5',
            '-d',
            'book',
            '--failure-level',
            'ERROR',
            '-r',
            'asciidoctor-diagram',
            '-a',
            'release-version=@0@'.format(meson.project_version()),
            '@INPUT@',
            '-D',
            '@OUTPUT@',
        ],
        input: adoc_files,
        output: 'manual',
        build_always_stale: true,
    )
else
    message('Asciidoctor not found, documentation not built')
endif

run_target('docs', command: ['echo', 'Built docs'], depends: alldocs)
