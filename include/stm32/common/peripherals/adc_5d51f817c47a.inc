
namespace adc {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_isr_tt = regs::adc_isr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_ier_tt = regs::adc_ier_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_cr_tt = regs::adc_cr_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_cfgr1_tt = regs::adc_adc_cfgr1_v9_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_cfgr2_tt = regs::adc_adc_cfgr2_v12_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_smpr_tt = regs::adc_adc_smpr_v6_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_awd1tr_tt = regs::adc_tr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_awd2tr_tt = regs::adc_awd2tr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_chselr0_tt = regs::adc_adc_chselr0_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_chselr1_tt = regs::adc_chselr_1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_awd3tr_tt = regs::adc_awd3tr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_dr_tt = regs::adc_dr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_awd2cr_tt = regs::adc_awd2cr_v4_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_awd3cr_tt = regs::adc_awd3cr_v4_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_calfact_tt = regs::adc_calfact_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_ccr_tt = regs::adc_adc_ccr_v8_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using adc_t =
    groov::group<"adc",
                 groov::mmio_bus<>,
                 adc_isr_tt<"adc_isr", baseaddress, 0x0>,
                 adc_ier_tt<"adc_ier", baseaddress, 0x4>,
                 adc_cr_tt<"adc_cr", baseaddress, 0x8>,
                 adc_cfgr1_tt<"adc_cfgr1", baseaddress, 0xc>,
                 adc_cfgr2_tt<"adc_cfgr2", baseaddress, 0x10>,
                 adc_smpr_tt<"adc_smpr", baseaddress, 0x14>,
                 adc_awd1tr_tt<"adc_awd1tr", baseaddress, 0x20>,
                 adc_awd2tr_tt<"adc_awd2tr", baseaddress, 0x24>,
                 adc_chselr0_tt<"adc_chselr0", baseaddress, 0x28>,
                 adc_chselr1_tt<"adc_chselr1", baseaddress, 0x28>,
                 adc_awd3tr_tt<"adc_awd3tr", baseaddress, 0x2c>,
                 adc_dr_tt<"adc_dr", baseaddress, 0x40>,
                 adc_awd2cr_tt<"adc_awd2cr", baseaddress, 0xa0>,
                 adc_awd3cr_tt<"adc_awd3cr", baseaddress, 0xa4>,
                 adc_calfact_tt<"adc_calfact", baseaddress, 0xb4>,
                 adc_ccr_tt<"adc_ccr", baseaddress, 0x308>>;

} // namespace adc
