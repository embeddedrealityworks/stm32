
namespace gpiob_s {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_moder_tt = regs::gpio_gpioa_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_otyper_tt = regs::gpio_gpioa_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_ospeedr_tt = regs::gpio_gpioa_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_pupdr_tt = regs::gpio_gpioa_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_idr_tt = regs::gpio_gpioa_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_odr_tt = regs::gpio_gpioa_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_bsrr_tt = regs::gpio_gpioa_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_lckr_tt = regs::gpio_gpioa_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_afrl_tt = regs::gpio_gpioa_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_afrh_tt = regs::gpio_gpioa_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_brr_tt = regs::gpio_gpioa_brr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_seccfgr_tt = regs::gpioa_gpioa_seccfgr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_privcfgr_tt = regs::gpdma_gpdma_privcfgr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_rcfglockr_tt = regs::gpio_gpioa_rcfglockr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_delayrl_tt = regs::gpio_gpioa_delayrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_delayrh_tt = regs::gpio_gpioa_delayrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_piocfgrl_tt = regs::gpio_gpioa_piocfgrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_piocfgrh_tt = regs::gpio_gpioa_piocfgrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_hwcfgr10_tt = regs::gpio_gpioa_hwcfgr10_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_hwcfgr9_tt = regs::gpio_gpioa_hwcfgr9_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_hwcfgr8_tt = regs::gpio_gpioa_hwcfgr8_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_hwcfgr7_tt = regs::gpio_gpioa_hwcfgr7_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_hwcfgr6_tt = regs::gpio_gpioa_hwcfgr6_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_hwcfgr5_tt = regs::gpio_gpioa_hwcfgr5_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_hwcfgr4_tt = regs::gpio_gpioa_hwcfgr4_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_hwcfgr3_tt = regs::gpio_gpioa_hwcfgr3_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_hwcfgr2_tt = regs::gpio_gpioa_hwcfgr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_hwcfgr1_tt = regs::gpio_gpioa_hwcfgr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_hwcfgr0_tt = regs::gpio_gpioa_hwcfgr0_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_verr_tt = regs::adc_adc_verr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_ipidr_tt = regs::gpio_gpioa_ipidr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiob_sidr_tt = regs::adc_adc_sidr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using gpiob_s_t =
    groov::group<"gpiob_s",
                 groov::mmio_bus<>,
                 gpiob_moder_tt<"gpiob_moder", baseaddress, 0x0>,
                 gpiob_otyper_tt<"gpiob_otyper", baseaddress, 0x4>,
                 gpiob_ospeedr_tt<"gpiob_ospeedr", baseaddress, 0x8>,
                 gpiob_pupdr_tt<"gpiob_pupdr", baseaddress, 0xc>,
                 gpiob_idr_tt<"gpiob_idr", baseaddress, 0x10>,
                 gpiob_odr_tt<"gpiob_odr", baseaddress, 0x14>,
                 gpiob_bsrr_tt<"gpiob_bsrr", baseaddress, 0x18>,
                 gpiob_lckr_tt<"gpiob_lckr", baseaddress, 0x1c>,
                 gpiob_afrl_tt<"gpiob_afrl", baseaddress, 0x20>,
                 gpiob_afrh_tt<"gpiob_afrh", baseaddress, 0x24>,
                 gpiob_brr_tt<"gpiob_brr", baseaddress, 0x28>,
                 gpiob_seccfgr_tt<"gpiob_seccfgr", baseaddress, 0x30>,
                 gpiob_privcfgr_tt<"gpiob_privcfgr", baseaddress, 0x34>,
                 gpiob_rcfglockr_tt<"gpiob_rcfglockr", baseaddress, 0x38>,
                 gpiob_delayrl_tt<"gpiob_delayrl", baseaddress, 0x40>,
                 gpiob_delayrh_tt<"gpiob_delayrh", baseaddress, 0x44>,
                 gpiob_piocfgrl_tt<"gpiob_piocfgrl", baseaddress, 0x48>,
                 gpiob_piocfgrh_tt<"gpiob_piocfgrh", baseaddress, 0x4c>,
                 gpiob_hwcfgr10_tt<"gpiob_hwcfgr10", baseaddress, 0x3c8>,
                 gpiob_hwcfgr9_tt<"gpiob_hwcfgr9", baseaddress, 0x3cc>,
                 gpiob_hwcfgr8_tt<"gpiob_hwcfgr8", baseaddress, 0x3d0>,
                 gpiob_hwcfgr7_tt<"gpiob_hwcfgr7", baseaddress, 0x3d4>,
                 gpiob_hwcfgr6_tt<"gpiob_hwcfgr6", baseaddress, 0x3d8>,
                 gpiob_hwcfgr5_tt<"gpiob_hwcfgr5", baseaddress, 0x3dc>,
                 gpiob_hwcfgr4_tt<"gpiob_hwcfgr4", baseaddress, 0x3e0>,
                 gpiob_hwcfgr3_tt<"gpiob_hwcfgr3", baseaddress, 0x3e4>,
                 gpiob_hwcfgr2_tt<"gpiob_hwcfgr2", baseaddress, 0x3e8>,
                 gpiob_hwcfgr1_tt<"gpiob_hwcfgr1", baseaddress, 0x3ec>,
                 gpiob_hwcfgr0_tt<"gpiob_hwcfgr0", baseaddress, 0x3f0>,
                 gpiob_verr_tt<"gpiob_verr", baseaddress, 0x3f4>,
                 gpiob_ipidr_tt<"gpiob_ipidr", baseaddress, 0x3f8>,
                 gpiob_sidr_tt<"gpiob_sidr", baseaddress, 0x3fc>>;

} // namespace gpiob_s
