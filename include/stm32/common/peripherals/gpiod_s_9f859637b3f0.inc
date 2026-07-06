
namespace gpiod_s {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_moder_tt = regs::gpio_gpioa_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_otyper_tt = regs::gpio_gpioa_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_ospeedr_tt = regs::gpio_gpioa_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_pupdr_tt = regs::gpio_gpioa_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_idr_tt = regs::gpio_gpioa_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_odr_tt = regs::gpio_gpioa_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_bsrr_tt = regs::gpio_gpioa_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_lckr_tt = regs::gpio_gpioa_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_afrl_tt = regs::gpio_gpioa_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_afrh_tt = regs::gpio_gpioa_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_brr_tt = regs::gpio_gpioa_brr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_seccfgr_tt = regs::gpioa_gpioa_seccfgr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_privcfgr_tt = regs::gpdma_gpdma_privcfgr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_rcfglockr_tt = regs::gpio_gpioa_rcfglockr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_delayrl_tt = regs::gpio_gpioa_delayrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_delayrh_tt = regs::gpio_gpioa_delayrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_piocfgrl_tt = regs::gpio_gpioa_piocfgrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_piocfgrh_tt = regs::gpio_gpioa_piocfgrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_hwcfgr10_tt = regs::gpio_gpioa_hwcfgr10_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_hwcfgr9_tt = regs::gpio_gpioa_hwcfgr9_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_hwcfgr8_tt = regs::gpio_gpioa_hwcfgr8_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_hwcfgr7_tt = regs::gpio_gpioa_hwcfgr7_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_hwcfgr6_tt = regs::gpio_gpioa_hwcfgr6_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_hwcfgr5_tt = regs::gpio_gpioa_hwcfgr5_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_hwcfgr4_tt = regs::gpio_gpioa_hwcfgr4_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_hwcfgr3_tt = regs::gpio_gpioa_hwcfgr3_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_hwcfgr2_tt = regs::gpio_gpioa_hwcfgr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_hwcfgr1_tt = regs::gpio_gpioa_hwcfgr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_hwcfgr0_tt = regs::gpio_gpioa_hwcfgr0_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_verr_tt = regs::adc_adc_verr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_ipidr_tt = regs::gpio_gpioa_ipidr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiod_sidr_tt = regs::adc_adc_sidr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using gpiod_s_t =
    groov::group<"gpiod_s",
                 groov::mmio_bus<>,
                 gpiod_moder_tt<"gpiod_moder", baseaddress, 0x0>,
                 gpiod_otyper_tt<"gpiod_otyper", baseaddress, 0x4>,
                 gpiod_ospeedr_tt<"gpiod_ospeedr", baseaddress, 0x8>,
                 gpiod_pupdr_tt<"gpiod_pupdr", baseaddress, 0xc>,
                 gpiod_idr_tt<"gpiod_idr", baseaddress, 0x10>,
                 gpiod_odr_tt<"gpiod_odr", baseaddress, 0x14>,
                 gpiod_bsrr_tt<"gpiod_bsrr", baseaddress, 0x18>,
                 gpiod_lckr_tt<"gpiod_lckr", baseaddress, 0x1c>,
                 gpiod_afrl_tt<"gpiod_afrl", baseaddress, 0x20>,
                 gpiod_afrh_tt<"gpiod_afrh", baseaddress, 0x24>,
                 gpiod_brr_tt<"gpiod_brr", baseaddress, 0x28>,
                 gpiod_seccfgr_tt<"gpiod_seccfgr", baseaddress, 0x30>,
                 gpiod_privcfgr_tt<"gpiod_privcfgr", baseaddress, 0x34>,
                 gpiod_rcfglockr_tt<"gpiod_rcfglockr", baseaddress, 0x38>,
                 gpiod_delayrl_tt<"gpiod_delayrl", baseaddress, 0x40>,
                 gpiod_delayrh_tt<"gpiod_delayrh", baseaddress, 0x44>,
                 gpiod_piocfgrl_tt<"gpiod_piocfgrl", baseaddress, 0x48>,
                 gpiod_piocfgrh_tt<"gpiod_piocfgrh", baseaddress, 0x4c>,
                 gpiod_hwcfgr10_tt<"gpiod_hwcfgr10", baseaddress, 0x3c8>,
                 gpiod_hwcfgr9_tt<"gpiod_hwcfgr9", baseaddress, 0x3cc>,
                 gpiod_hwcfgr8_tt<"gpiod_hwcfgr8", baseaddress, 0x3d0>,
                 gpiod_hwcfgr7_tt<"gpiod_hwcfgr7", baseaddress, 0x3d4>,
                 gpiod_hwcfgr6_tt<"gpiod_hwcfgr6", baseaddress, 0x3d8>,
                 gpiod_hwcfgr5_tt<"gpiod_hwcfgr5", baseaddress, 0x3dc>,
                 gpiod_hwcfgr4_tt<"gpiod_hwcfgr4", baseaddress, 0x3e0>,
                 gpiod_hwcfgr3_tt<"gpiod_hwcfgr3", baseaddress, 0x3e4>,
                 gpiod_hwcfgr2_tt<"gpiod_hwcfgr2", baseaddress, 0x3e8>,
                 gpiod_hwcfgr1_tt<"gpiod_hwcfgr1", baseaddress, 0x3ec>,
                 gpiod_hwcfgr0_tt<"gpiod_hwcfgr0", baseaddress, 0x3f0>,
                 gpiod_verr_tt<"gpiod_verr", baseaddress, 0x3f4>,
                 gpiod_ipidr_tt<"gpiod_ipidr", baseaddress, 0x3f8>,
                 gpiod_sidr_tt<"gpiod_sidr", baseaddress, 0x3fc>>;

} // namespace gpiod_s
