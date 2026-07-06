
namespace dlybx {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dlyb_cr_tt = regs::dlyb_dlyb_cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dlyb_cfgr_tt = regs::dlyb_dlyb_cfgr_v1_tt<name, baseaddress, offset>;

  template <stdx::ct_string name, std::uint32_t baseaddress>
  using dlybx_t =
    groov::group<name,
                 groov::mmio_bus<>,
                 dlyb_cr_tt<"dlyb_cr", baseaddress, 0x0>,
                 dlyb_cfgr_tt<"dlyb_cfgr", baseaddress, 0x4>>;

} // namespace dlybx
