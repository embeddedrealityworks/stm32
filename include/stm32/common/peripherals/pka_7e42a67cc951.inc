
namespace pka {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr_tt = regs::pka_pka_cr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using sr_tt = regs::pka_pka_sr_v4_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using clrfr_tt = regs::pka_pka_clrfr_v4_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using pka_t =
    groov::group<"pka",
                 groov::mmio_bus<>,
                 cr_tt<"cr", baseaddress, 0x0>,
                 sr_tt<"sr", baseaddress, 0x4>,
                 clrfr_tt<"clrfr", baseaddress, 0x8>>;

} // namespace pka
