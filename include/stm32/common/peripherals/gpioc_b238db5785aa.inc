
namespace gpioc {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_moder_tt = regs::gpio_gpioa_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_otyper_tt = regs::gpio_gpioa_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_ospeedr_tt = regs::gpio_gpioa_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_pupdr_tt = regs::gpio_gpioa_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_idr_tt = regs::gpio_gpioa_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_odr_tt = regs::gpio_gpioa_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_bsrr_tt = regs::gpio_gpioa_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_lckr_tt = regs::gpio_gpioa_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_afrl_tt = regs::gpio_gpioa_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_afrh_tt = regs::gpio_gpioa_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_brr_tt = regs::gpio_gpioa_brr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_seccfgr_tt = regs::gpioa_gpioa_seccfgr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_privcfgr_tt = regs::gpdma_gpdma_privcfgr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_rcfglockr_tt = regs::gpio_gpioa_rcfglockr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_delayrl_tt = regs::gpio_gpioa_delayrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_delayrh_tt = regs::gpio_gpioa_delayrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_piocfgrl_tt = regs::gpio_gpioa_piocfgrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_piocfgrh_tt = regs::gpio_gpioa_piocfgrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_hwcfgr10_tt = regs::gpio_gpioa_hwcfgr10_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_hwcfgr9_tt = regs::gpio_gpioa_hwcfgr9_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_hwcfgr8_tt = regs::gpio_gpioa_hwcfgr8_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_hwcfgr7_tt = regs::gpio_gpioa_hwcfgr7_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_hwcfgr6_tt = regs::gpio_gpioa_hwcfgr6_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_hwcfgr5_tt = regs::gpio_gpioa_hwcfgr5_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_hwcfgr4_tt = regs::gpio_gpioa_hwcfgr4_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_hwcfgr3_tt = regs::gpio_gpioa_hwcfgr3_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_hwcfgr2_tt = regs::gpio_gpioa_hwcfgr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_hwcfgr1_tt = regs::gpio_gpioa_hwcfgr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_hwcfgr0_tt = regs::gpio_gpioa_hwcfgr0_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_verr_tt = regs::adc_adc_verr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_ipidr_tt = regs::gpio_gpioa_ipidr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_sidr_tt = regs::adc_adc_sidr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using gpioc_t =
    groov::group<"gpioc",
                 groov::mmio_bus<>,
                 gpioc_moder_tt<"gpioc_moder", baseaddress, 0x0>,
                 gpioc_otyper_tt<"gpioc_otyper", baseaddress, 0x4>,
                 gpioc_ospeedr_tt<"gpioc_ospeedr", baseaddress, 0x8>,
                 gpioc_pupdr_tt<"gpioc_pupdr", baseaddress, 0xc>,
                 gpioc_idr_tt<"gpioc_idr", baseaddress, 0x10>,
                 gpioc_odr_tt<"gpioc_odr", baseaddress, 0x14>,
                 gpioc_bsrr_tt<"gpioc_bsrr", baseaddress, 0x18>,
                 gpioc_lckr_tt<"gpioc_lckr", baseaddress, 0x1c>,
                 gpioc_afrl_tt<"gpioc_afrl", baseaddress, 0x20>,
                 gpioc_afrh_tt<"gpioc_afrh", baseaddress, 0x24>,
                 gpioc_brr_tt<"gpioc_brr", baseaddress, 0x28>,
                 gpioc_seccfgr_tt<"gpioc_seccfgr", baseaddress, 0x30>,
                 gpioc_privcfgr_tt<"gpioc_privcfgr", baseaddress, 0x34>,
                 gpioc_rcfglockr_tt<"gpioc_rcfglockr", baseaddress, 0x38>,
                 gpioc_delayrl_tt<"gpioc_delayrl", baseaddress, 0x40>,
                 gpioc_delayrh_tt<"gpioc_delayrh", baseaddress, 0x44>,
                 gpioc_piocfgrl_tt<"gpioc_piocfgrl", baseaddress, 0x48>,
                 gpioc_piocfgrh_tt<"gpioc_piocfgrh", baseaddress, 0x4c>,
                 gpioc_hwcfgr10_tt<"gpioc_hwcfgr10", baseaddress, 0x3c8>,
                 gpioc_hwcfgr9_tt<"gpioc_hwcfgr9", baseaddress, 0x3cc>,
                 gpioc_hwcfgr8_tt<"gpioc_hwcfgr8", baseaddress, 0x3d0>,
                 gpioc_hwcfgr7_tt<"gpioc_hwcfgr7", baseaddress, 0x3d4>,
                 gpioc_hwcfgr6_tt<"gpioc_hwcfgr6", baseaddress, 0x3d8>,
                 gpioc_hwcfgr5_tt<"gpioc_hwcfgr5", baseaddress, 0x3dc>,
                 gpioc_hwcfgr4_tt<"gpioc_hwcfgr4", baseaddress, 0x3e0>,
                 gpioc_hwcfgr3_tt<"gpioc_hwcfgr3", baseaddress, 0x3e4>,
                 gpioc_hwcfgr2_tt<"gpioc_hwcfgr2", baseaddress, 0x3e8>,
                 gpioc_hwcfgr1_tt<"gpioc_hwcfgr1", baseaddress, 0x3ec>,
                 gpioc_hwcfgr0_tt<"gpioc_hwcfgr0", baseaddress, 0x3f0>,
                 gpioc_verr_tt<"gpioc_verr", baseaddress, 0x3f4>,
                 gpioc_ipidr_tt<"gpioc_ipidr", baseaddress, 0x3f8>,
                 gpioc_sidr_tt<"gpioc_sidr", baseaddress, 0x3fc>>;

} // namespace gpioc
