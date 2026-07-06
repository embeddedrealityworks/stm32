
namespace gpiop_s {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_moder_tt = regs::gpio_gpioa_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_otyper_tt = regs::gpio_gpioa_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_ospeedr_tt = regs::gpio_gpioa_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_pupdr_tt = regs::gpio_gpioa_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_idr_tt = regs::gpio_gpioa_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_odr_tt = regs::gpio_gpioa_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_bsrr_tt = regs::gpio_gpioa_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_lckr_tt = regs::gpio_gpioa_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_afrl_tt = regs::gpio_gpioa_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_afrh_tt = regs::gpio_gpioa_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_brr_tt = regs::gpio_gpioa_brr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_seccfgr_tt = regs::gpioa_gpioa_seccfgr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_privcfgr_tt = regs::gpdma_gpdma_privcfgr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_rcfglockr_tt = regs::gpio_gpioa_rcfglockr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_delayrl_tt = regs::gpio_gpioa_delayrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_delayrh_tt = regs::gpio_gpioa_delayrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_piocfgrl_tt = regs::gpio_gpioa_piocfgrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_piocfgrh_tt = regs::gpio_gpioa_piocfgrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_hwcfgr10_tt = regs::gpio_gpioa_hwcfgr10_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_hwcfgr9_tt = regs::gpio_gpioa_hwcfgr9_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_hwcfgr8_tt = regs::gpio_gpioa_hwcfgr8_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_hwcfgr7_tt = regs::gpio_gpioa_hwcfgr7_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_hwcfgr6_tt = regs::gpio_gpioa_hwcfgr6_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_hwcfgr5_tt = regs::gpio_gpioa_hwcfgr5_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_hwcfgr4_tt = regs::gpio_gpioa_hwcfgr4_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_hwcfgr3_tt = regs::gpio_gpioa_hwcfgr3_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_hwcfgr2_tt = regs::gpio_gpioa_hwcfgr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_hwcfgr1_tt = regs::gpio_gpioa_hwcfgr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_hwcfgr0_tt = regs::gpio_gpioa_hwcfgr0_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_verr_tt = regs::adc_adc_verr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_ipidr_tt = regs::gpio_gpioa_ipidr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiop_sidr_tt = regs::adc_adc_sidr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using gpiop_s_t =
    groov::group<"gpiop_s",
                 groov::mmio_bus<>,
                 gpiop_moder_tt<"gpiop_moder", baseaddress, 0x0>,
                 gpiop_otyper_tt<"gpiop_otyper", baseaddress, 0x4>,
                 gpiop_ospeedr_tt<"gpiop_ospeedr", baseaddress, 0x8>,
                 gpiop_pupdr_tt<"gpiop_pupdr", baseaddress, 0xc>,
                 gpiop_idr_tt<"gpiop_idr", baseaddress, 0x10>,
                 gpiop_odr_tt<"gpiop_odr", baseaddress, 0x14>,
                 gpiop_bsrr_tt<"gpiop_bsrr", baseaddress, 0x18>,
                 gpiop_lckr_tt<"gpiop_lckr", baseaddress, 0x1c>,
                 gpiop_afrl_tt<"gpiop_afrl", baseaddress, 0x20>,
                 gpiop_afrh_tt<"gpiop_afrh", baseaddress, 0x24>,
                 gpiop_brr_tt<"gpiop_brr", baseaddress, 0x28>,
                 gpiop_seccfgr_tt<"gpiop_seccfgr", baseaddress, 0x30>,
                 gpiop_privcfgr_tt<"gpiop_privcfgr", baseaddress, 0x34>,
                 gpiop_rcfglockr_tt<"gpiop_rcfglockr", baseaddress, 0x38>,
                 gpiop_delayrl_tt<"gpiop_delayrl", baseaddress, 0x40>,
                 gpiop_delayrh_tt<"gpiop_delayrh", baseaddress, 0x44>,
                 gpiop_piocfgrl_tt<"gpiop_piocfgrl", baseaddress, 0x48>,
                 gpiop_piocfgrh_tt<"gpiop_piocfgrh", baseaddress, 0x4c>,
                 gpiop_hwcfgr10_tt<"gpiop_hwcfgr10", baseaddress, 0x3c8>,
                 gpiop_hwcfgr9_tt<"gpiop_hwcfgr9", baseaddress, 0x3cc>,
                 gpiop_hwcfgr8_tt<"gpiop_hwcfgr8", baseaddress, 0x3d0>,
                 gpiop_hwcfgr7_tt<"gpiop_hwcfgr7", baseaddress, 0x3d4>,
                 gpiop_hwcfgr6_tt<"gpiop_hwcfgr6", baseaddress, 0x3d8>,
                 gpiop_hwcfgr5_tt<"gpiop_hwcfgr5", baseaddress, 0x3dc>,
                 gpiop_hwcfgr4_tt<"gpiop_hwcfgr4", baseaddress, 0x3e0>,
                 gpiop_hwcfgr3_tt<"gpiop_hwcfgr3", baseaddress, 0x3e4>,
                 gpiop_hwcfgr2_tt<"gpiop_hwcfgr2", baseaddress, 0x3e8>,
                 gpiop_hwcfgr1_tt<"gpiop_hwcfgr1", baseaddress, 0x3ec>,
                 gpiop_hwcfgr0_tt<"gpiop_hwcfgr0", baseaddress, 0x3f0>,
                 gpiop_verr_tt<"gpiop_verr", baseaddress, 0x3f4>,
                 gpiop_ipidr_tt<"gpiop_ipidr", baseaddress, 0x3f8>,
                 gpiop_sidr_tt<"gpiop_sidr", baseaddress, 0x3fc>>;

} // namespace gpiop_s
