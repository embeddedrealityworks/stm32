
namespace gpioh {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_moder_tt = regs::gpio_gpioa_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_otyper_tt = regs::gpio_gpioa_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_ospeedr_tt = regs::gpio_gpioa_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_pupdr_tt = regs::gpio_gpioa_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_idr_tt = regs::gpio_gpioa_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_odr_tt = regs::gpio_gpioa_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_bsrr_tt = regs::gpio_gpioa_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_lckr_tt = regs::gpio_gpioa_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_afrl_tt = regs::gpio_gpioa_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_afrh_tt = regs::gpio_gpioa_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_brr_tt = regs::gpio_gpioa_brr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_seccfgr_tt = regs::gpioa_gpioa_seccfgr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_privcfgr_tt = regs::gpdma_gpdma_privcfgr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_rcfglockr_tt = regs::gpio_gpioa_rcfglockr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_delayrl_tt = regs::gpio_gpioa_delayrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_delayrh_tt = regs::gpio_gpioa_delayrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_piocfgrl_tt = regs::gpio_gpioa_piocfgrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_piocfgrh_tt = regs::gpio_gpioa_piocfgrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_hwcfgr10_tt = regs::gpio_gpioa_hwcfgr10_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_hwcfgr9_tt = regs::gpio_gpioa_hwcfgr9_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_hwcfgr8_tt = regs::gpio_gpioa_hwcfgr8_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_hwcfgr7_tt = regs::gpio_gpioa_hwcfgr7_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_hwcfgr6_tt = regs::gpio_gpioa_hwcfgr6_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_hwcfgr5_tt = regs::gpio_gpioa_hwcfgr5_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_hwcfgr4_tt = regs::gpio_gpioa_hwcfgr4_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_hwcfgr3_tt = regs::gpio_gpioa_hwcfgr3_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_hwcfgr2_tt = regs::gpio_gpioa_hwcfgr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_hwcfgr1_tt = regs::gpio_gpioa_hwcfgr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_hwcfgr0_tt = regs::gpio_gpioa_hwcfgr0_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_verr_tt = regs::adc_adc_verr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_ipidr_tt = regs::gpio_gpioa_ipidr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_sidr_tt = regs::adc_adc_sidr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using gpioh_t =
    groov::group<"gpioh",
                 groov::mmio_bus<>,
                 gpioh_moder_tt<"gpioh_moder", baseaddress, 0x0>,
                 gpioh_otyper_tt<"gpioh_otyper", baseaddress, 0x4>,
                 gpioh_ospeedr_tt<"gpioh_ospeedr", baseaddress, 0x8>,
                 gpioh_pupdr_tt<"gpioh_pupdr", baseaddress, 0xc>,
                 gpioh_idr_tt<"gpioh_idr", baseaddress, 0x10>,
                 gpioh_odr_tt<"gpioh_odr", baseaddress, 0x14>,
                 gpioh_bsrr_tt<"gpioh_bsrr", baseaddress, 0x18>,
                 gpioh_lckr_tt<"gpioh_lckr", baseaddress, 0x1c>,
                 gpioh_afrl_tt<"gpioh_afrl", baseaddress, 0x20>,
                 gpioh_afrh_tt<"gpioh_afrh", baseaddress, 0x24>,
                 gpioh_brr_tt<"gpioh_brr", baseaddress, 0x28>,
                 gpioh_seccfgr_tt<"gpioh_seccfgr", baseaddress, 0x30>,
                 gpioh_privcfgr_tt<"gpioh_privcfgr", baseaddress, 0x34>,
                 gpioh_rcfglockr_tt<"gpioh_rcfglockr", baseaddress, 0x38>,
                 gpioh_delayrl_tt<"gpioh_delayrl", baseaddress, 0x40>,
                 gpioh_delayrh_tt<"gpioh_delayrh", baseaddress, 0x44>,
                 gpioh_piocfgrl_tt<"gpioh_piocfgrl", baseaddress, 0x48>,
                 gpioh_piocfgrh_tt<"gpioh_piocfgrh", baseaddress, 0x4c>,
                 gpioh_hwcfgr10_tt<"gpioh_hwcfgr10", baseaddress, 0x3c8>,
                 gpioh_hwcfgr9_tt<"gpioh_hwcfgr9", baseaddress, 0x3cc>,
                 gpioh_hwcfgr8_tt<"gpioh_hwcfgr8", baseaddress, 0x3d0>,
                 gpioh_hwcfgr7_tt<"gpioh_hwcfgr7", baseaddress, 0x3d4>,
                 gpioh_hwcfgr6_tt<"gpioh_hwcfgr6", baseaddress, 0x3d8>,
                 gpioh_hwcfgr5_tt<"gpioh_hwcfgr5", baseaddress, 0x3dc>,
                 gpioh_hwcfgr4_tt<"gpioh_hwcfgr4", baseaddress, 0x3e0>,
                 gpioh_hwcfgr3_tt<"gpioh_hwcfgr3", baseaddress, 0x3e4>,
                 gpioh_hwcfgr2_tt<"gpioh_hwcfgr2", baseaddress, 0x3e8>,
                 gpioh_hwcfgr1_tt<"gpioh_hwcfgr1", baseaddress, 0x3ec>,
                 gpioh_hwcfgr0_tt<"gpioh_hwcfgr0", baseaddress, 0x3f0>,
                 gpioh_verr_tt<"gpioh_verr", baseaddress, 0x3f4>,
                 gpioh_ipidr_tt<"gpioh_ipidr", baseaddress, 0x3f8>,
                 gpioh_sidr_tt<"gpioh_sidr", baseaddress, 0x3fc>>;

} // namespace gpioh
