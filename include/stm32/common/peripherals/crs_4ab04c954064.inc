
namespace crs {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using crs_cr_tt = regs::crs_cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using crs_cfgr_tt = regs::crs_cfgr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using crs_isr_tt = regs::crs_isr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using crs_icr_tt = regs::crs_icr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using crs_t =
    groov::group<"crs",
                 groov::mmio_bus<>,
                 crs_cr_tt<"crs_cr", baseaddress, 0x0>,
                 crs_cfgr_tt<"crs_cfgr", baseaddress, 0x4>,
                 crs_isr_tt<"crs_isr", baseaddress, 0x8>,
                 crs_icr_tt<"crs_icr", baseaddress, 0xc>>;

} // namespace crs
