
namespace gpiog {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_moder_tt = regs::gpio_gpioa_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_otyper_tt = regs::gpio_gpioa_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_ospeedr_tt = regs::gpio_gpioa_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_pupdr_tt = regs::gpio_gpioa_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_idr_tt = regs::gpio_gpioa_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_odr_tt = regs::gpio_gpioa_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_bsrr_tt = regs::gpio_gpioa_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_lckr_tt = regs::gpio_gpioa_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_afrl_tt = regs::gpio_gpioa_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_afrh_tt = regs::gpio_gpioa_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_brr_tt = regs::gpio_gpioa_brr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_seccfgr_tt = regs::gpioa_gpioa_seccfgr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_privcfgr_tt = regs::gpdma_gpdma_privcfgr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_rcfglockr_tt = regs::gpio_gpioa_rcfglockr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_delayrl_tt = regs::gpio_gpioa_delayrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_delayrh_tt = regs::gpio_gpioa_delayrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_piocfgrl_tt = regs::gpio_gpioa_piocfgrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_piocfgrh_tt = regs::gpio_gpioa_piocfgrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_hwcfgr10_tt = regs::gpio_gpioa_hwcfgr10_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_hwcfgr9_tt = regs::gpio_gpioa_hwcfgr9_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_hwcfgr8_tt = regs::gpio_gpioa_hwcfgr8_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_hwcfgr7_tt = regs::gpio_gpioa_hwcfgr7_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_hwcfgr6_tt = regs::gpio_gpioa_hwcfgr6_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_hwcfgr5_tt = regs::gpio_gpioa_hwcfgr5_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_hwcfgr4_tt = regs::gpio_gpioa_hwcfgr4_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_hwcfgr3_tt = regs::gpio_gpioa_hwcfgr3_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_hwcfgr2_tt = regs::gpio_gpioa_hwcfgr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_hwcfgr1_tt = regs::gpio_gpioa_hwcfgr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_hwcfgr0_tt = regs::gpio_gpioa_hwcfgr0_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_verr_tt = regs::adc_adc_verr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_ipidr_tt = regs::gpio_gpioa_ipidr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiog_sidr_tt = regs::adc_adc_sidr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using gpiog_t =
    groov::group<"gpiog",
                 groov::mmio_bus<>,
                 gpiog_moder_tt<"gpiog_moder", baseaddress, 0x0>,
                 gpiog_otyper_tt<"gpiog_otyper", baseaddress, 0x4>,
                 gpiog_ospeedr_tt<"gpiog_ospeedr", baseaddress, 0x8>,
                 gpiog_pupdr_tt<"gpiog_pupdr", baseaddress, 0xc>,
                 gpiog_idr_tt<"gpiog_idr", baseaddress, 0x10>,
                 gpiog_odr_tt<"gpiog_odr", baseaddress, 0x14>,
                 gpiog_bsrr_tt<"gpiog_bsrr", baseaddress, 0x18>,
                 gpiog_lckr_tt<"gpiog_lckr", baseaddress, 0x1c>,
                 gpiog_afrl_tt<"gpiog_afrl", baseaddress, 0x20>,
                 gpiog_afrh_tt<"gpiog_afrh", baseaddress, 0x24>,
                 gpiog_brr_tt<"gpiog_brr", baseaddress, 0x28>,
                 gpiog_seccfgr_tt<"gpiog_seccfgr", baseaddress, 0x30>,
                 gpiog_privcfgr_tt<"gpiog_privcfgr", baseaddress, 0x34>,
                 gpiog_rcfglockr_tt<"gpiog_rcfglockr", baseaddress, 0x38>,
                 gpiog_delayrl_tt<"gpiog_delayrl", baseaddress, 0x40>,
                 gpiog_delayrh_tt<"gpiog_delayrh", baseaddress, 0x44>,
                 gpiog_piocfgrl_tt<"gpiog_piocfgrl", baseaddress, 0x48>,
                 gpiog_piocfgrh_tt<"gpiog_piocfgrh", baseaddress, 0x4c>,
                 gpiog_hwcfgr10_tt<"gpiog_hwcfgr10", baseaddress, 0x3c8>,
                 gpiog_hwcfgr9_tt<"gpiog_hwcfgr9", baseaddress, 0x3cc>,
                 gpiog_hwcfgr8_tt<"gpiog_hwcfgr8", baseaddress, 0x3d0>,
                 gpiog_hwcfgr7_tt<"gpiog_hwcfgr7", baseaddress, 0x3d4>,
                 gpiog_hwcfgr6_tt<"gpiog_hwcfgr6", baseaddress, 0x3d8>,
                 gpiog_hwcfgr5_tt<"gpiog_hwcfgr5", baseaddress, 0x3dc>,
                 gpiog_hwcfgr4_tt<"gpiog_hwcfgr4", baseaddress, 0x3e0>,
                 gpiog_hwcfgr3_tt<"gpiog_hwcfgr3", baseaddress, 0x3e4>,
                 gpiog_hwcfgr2_tt<"gpiog_hwcfgr2", baseaddress, 0x3e8>,
                 gpiog_hwcfgr1_tt<"gpiog_hwcfgr1", baseaddress, 0x3ec>,
                 gpiog_hwcfgr0_tt<"gpiog_hwcfgr0", baseaddress, 0x3f0>,
                 gpiog_verr_tt<"gpiog_verr", baseaddress, 0x3f4>,
                 gpiog_ipidr_tt<"gpiog_ipidr", baseaddress, 0x3f8>,
                 gpiog_sidr_tt<"gpiog_sidr", baseaddress, 0x3fc>>;

} // namespace gpiog
