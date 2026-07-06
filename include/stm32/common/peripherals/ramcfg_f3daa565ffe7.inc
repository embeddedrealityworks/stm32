
namespace ramcfg {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ramcfg_m1cr_tt = regs::ramcfg_ramcfg_m1cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ramcfg_m1isr_tt = regs::ramcfg_ramcfg_axisram1isr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ramcfg_m1erkeyr_tt = regs::ramcfg_ramcfg_m1erkeyr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ramcfg_m2cr_tt = regs::ramcfg_ramcfg_m2cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ramcfg_m2ier_tt = regs::ramcfg_ramcfg_m2ier_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ramcfg_m2isr_tt = regs::ramcfg_ramcfg_m2isr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ramcfg_m2pear_tt = regs::ramcfg_ramcfg_m2pear_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ramcfg_m2icr_tt = regs::ramcfg_ramcfg_m2icr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ramcfg_m2wpr1_tt = regs::ramcfg_ramcfg_m2wpr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ramcfg_m2wpr2_tt = regs::ramcfg_ramcfg_m2wpr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ramcfg_m2erkeyr_tt = regs::ramcfg_ramcfg_m1erkeyr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using ramcfg_t =
    groov::group<"ramcfg",
                 groov::mmio_bus<>,
                 ramcfg_m1cr_tt<"ramcfg_m1cr", baseaddress, 0x0>,
                 ramcfg_m1isr_tt<"ramcfg_m1isr", baseaddress, 0x8>,
                 ramcfg_m1erkeyr_tt<"ramcfg_m1erkeyr", baseaddress, 0x28>,
                 ramcfg_m2cr_tt<"ramcfg_m2cr", baseaddress, 0x40>,
                 ramcfg_m2ier_tt<"ramcfg_m2ier", baseaddress, 0x44>,
                 ramcfg_m2isr_tt<"ramcfg_m2isr", baseaddress, 0x48>,
                 ramcfg_m2pear_tt<"ramcfg_m2pear", baseaddress, 0x50>,
                 ramcfg_m2icr_tt<"ramcfg_m2icr", baseaddress, 0x54>,
                 ramcfg_m2wpr1_tt<"ramcfg_m2wpr1", baseaddress, 0x58>,
                 ramcfg_m2wpr2_tt<"ramcfg_m2wpr2", baseaddress, 0x5c>,
                 ramcfg_m2erkeyr_tt<"ramcfg_m2erkeyr", baseaddress, 0x68>>;

} // namespace ramcfg
