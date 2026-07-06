
namespace gpioq {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_moder_tt = regs::gpio_gpioa_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_otyper_tt = regs::gpio_gpioa_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_ospeedr_tt = regs::gpio_gpioa_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_pupdr_tt = regs::gpio_gpioa_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_idr_tt = regs::gpio_gpioa_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_odr_tt = regs::gpio_gpioa_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_bsrr_tt = regs::gpio_gpioa_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_lckr_tt = regs::gpio_gpioa_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_afrl_tt = regs::gpio_gpioa_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_afrh_tt = regs::gpio_gpioa_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_brr_tt = regs::gpio_gpioa_brr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_seccfgr_tt = regs::gpioa_gpioa_seccfgr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_privcfgr_tt = regs::gpdma_gpdma_privcfgr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_rcfglockr_tt = regs::gpio_gpioa_rcfglockr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_delayrl_tt = regs::gpio_gpioa_delayrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_delayrh_tt = regs::gpio_gpioa_delayrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_piocfgrl_tt = regs::gpio_gpioa_piocfgrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_piocfgrh_tt = regs::gpio_gpioa_piocfgrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_hwcfgr10_tt = regs::gpio_gpioa_hwcfgr10_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_hwcfgr9_tt = regs::gpio_gpioa_hwcfgr9_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_hwcfgr8_tt = regs::gpio_gpioa_hwcfgr8_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_hwcfgr7_tt = regs::gpio_gpioa_hwcfgr7_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_hwcfgr6_tt = regs::gpio_gpioa_hwcfgr6_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_hwcfgr5_tt = regs::gpio_gpioa_hwcfgr5_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_hwcfgr4_tt = regs::gpio_gpioa_hwcfgr4_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_hwcfgr3_tt = regs::gpio_gpioa_hwcfgr3_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_hwcfgr2_tt = regs::gpio_gpioa_hwcfgr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_hwcfgr1_tt = regs::gpio_gpioa_hwcfgr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_hwcfgr0_tt = regs::gpio_gpioa_hwcfgr0_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_verr_tt = regs::adc_adc_verr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_ipidr_tt = regs::gpio_gpioa_ipidr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioq_sidr_tt = regs::adc_adc_sidr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using gpioq_t =
    groov::group<"gpioq",
                 groov::mmio_bus<>,
                 gpioq_moder_tt<"gpioq_moder", baseaddress, 0x0>,
                 gpioq_otyper_tt<"gpioq_otyper", baseaddress, 0x4>,
                 gpioq_ospeedr_tt<"gpioq_ospeedr", baseaddress, 0x8>,
                 gpioq_pupdr_tt<"gpioq_pupdr", baseaddress, 0xc>,
                 gpioq_idr_tt<"gpioq_idr", baseaddress, 0x10>,
                 gpioq_odr_tt<"gpioq_odr", baseaddress, 0x14>,
                 gpioq_bsrr_tt<"gpioq_bsrr", baseaddress, 0x18>,
                 gpioq_lckr_tt<"gpioq_lckr", baseaddress, 0x1c>,
                 gpioq_afrl_tt<"gpioq_afrl", baseaddress, 0x20>,
                 gpioq_afrh_tt<"gpioq_afrh", baseaddress, 0x24>,
                 gpioq_brr_tt<"gpioq_brr", baseaddress, 0x28>,
                 gpioq_seccfgr_tt<"gpioq_seccfgr", baseaddress, 0x30>,
                 gpioq_privcfgr_tt<"gpioq_privcfgr", baseaddress, 0x34>,
                 gpioq_rcfglockr_tt<"gpioq_rcfglockr", baseaddress, 0x38>,
                 gpioq_delayrl_tt<"gpioq_delayrl", baseaddress, 0x40>,
                 gpioq_delayrh_tt<"gpioq_delayrh", baseaddress, 0x44>,
                 gpioq_piocfgrl_tt<"gpioq_piocfgrl", baseaddress, 0x48>,
                 gpioq_piocfgrh_tt<"gpioq_piocfgrh", baseaddress, 0x4c>,
                 gpioq_hwcfgr10_tt<"gpioq_hwcfgr10", baseaddress, 0x3c8>,
                 gpioq_hwcfgr9_tt<"gpioq_hwcfgr9", baseaddress, 0x3cc>,
                 gpioq_hwcfgr8_tt<"gpioq_hwcfgr8", baseaddress, 0x3d0>,
                 gpioq_hwcfgr7_tt<"gpioq_hwcfgr7", baseaddress, 0x3d4>,
                 gpioq_hwcfgr6_tt<"gpioq_hwcfgr6", baseaddress, 0x3d8>,
                 gpioq_hwcfgr5_tt<"gpioq_hwcfgr5", baseaddress, 0x3dc>,
                 gpioq_hwcfgr4_tt<"gpioq_hwcfgr4", baseaddress, 0x3e0>,
                 gpioq_hwcfgr3_tt<"gpioq_hwcfgr3", baseaddress, 0x3e4>,
                 gpioq_hwcfgr2_tt<"gpioq_hwcfgr2", baseaddress, 0x3e8>,
                 gpioq_hwcfgr1_tt<"gpioq_hwcfgr1", baseaddress, 0x3ec>,
                 gpioq_hwcfgr0_tt<"gpioq_hwcfgr0", baseaddress, 0x3f0>,
                 gpioq_verr_tt<"gpioq_verr", baseaddress, 0x3f4>,
                 gpioq_ipidr_tt<"gpioq_ipidr", baseaddress, 0x3f8>,
                 gpioq_sidr_tt<"gpioq_sidr", baseaddress, 0x3fc>>;

} // namespace gpioq
