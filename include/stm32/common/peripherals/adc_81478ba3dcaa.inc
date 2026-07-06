
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
  using cfgr1_tt = regs::adc_cfgr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cfgr2_tt = regs::adc_cfgr2_v7_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using smpr_tt = regs::adc_smpr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using adc_tr_tt = regs::adc_tr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using chselr0_tt = regs::adc_chselr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using chselr1_tt = regs::adc_chselr_1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dr_tt = regs::adc_dr_v1_tt<name, baseaddress, offset>;
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
                 cfgr1_tt<"cfgr1", baseaddress, 0xc>,
                 cfgr2_tt<"cfgr2", baseaddress, 0x10>,
                 smpr_tt<"smpr", baseaddress, 0x14>,
                 adc_tr_tt<"adc_tr", baseaddress, 0x20>,
                 chselr0_tt<"chselr0", baseaddress, 0x28>,
                 chselr1_tt<"chselr1", baseaddress, 0x28>,
                 dr_tt<"dr", baseaddress, 0x40>,
                 calfact_tt<"calfact", baseaddress, 0xb4>,
                 ccr_tt<"ccr", baseaddress, 0x308>>;

} // namespace adc
