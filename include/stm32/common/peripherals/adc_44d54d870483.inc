
namespace adc {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using isr_tt = regs::adc_isr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ier_tt = regs::adc_ier_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr_tt = regs::adc_cr_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_cfgr1_tt = regs::adc_adc_cfgr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_cfgr2_tt = regs::adc_adc_cfgr2_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using smpr_tt = regs::adc_smpr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using awd1tr_tt = regs::adc_tr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using awd2tr_tt = regs::adc_awd2tr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using chselr_tt = regs::adc_chselr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using chselr_1_tt = regs::adc_chselr_1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using awd3tr_tt = regs::adc_awd3tr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dr_tt = regs::adc_dr_v4_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using awd2cr_tt = regs::adc_awd2cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using awd3cr_tt = regs::adc_awd3cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using calfact_tt = regs::adc_calfact_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccr_tt = regs::adc_ccr_v6_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using adc_t =
    groov::group<"adc",
                 groov::mmio_bus<>,
                 isr_tt<"isr", baseaddress, 0x0>,
                 ier_tt<"ier", baseaddress, 0x4>,
                 cr_tt<"cr", baseaddress, 0x8>,
                 adc_cfgr1_tt<"adc_cfgr1", baseaddress, 0xc>,
                 adc_cfgr2_tt<"adc_cfgr2", baseaddress, 0x10>,
                 smpr_tt<"smpr", baseaddress, 0x14>,
                 awd1tr_tt<"awd1tr", baseaddress, 0x20>,
                 awd2tr_tt<"awd2tr", baseaddress, 0x24>,
                 chselr_tt<"chselr", baseaddress, 0x28>,
                 chselr_1_tt<"chselr_1", baseaddress, 0x28>,
                 awd3tr_tt<"awd3tr", baseaddress, 0x2c>,
                 dr_tt<"dr", baseaddress, 0x40>,
                 awd2cr_tt<"awd2cr", baseaddress, 0xa0>,
                 awd3cr_tt<"awd3cr", baseaddress, 0xa4>,
                 calfact_tt<"calfact", baseaddress, 0xb4>,
                 ccr_tt<"ccr", baseaddress, 0x308>>;

} // namespace adc
