
namespace gpioo_s {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_moder_tt = regs::gpio_gpioa_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_otyper_tt = regs::gpio_gpioa_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_ospeedr_tt = regs::gpio_gpioa_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_pupdr_tt = regs::gpio_gpioa_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_idr_tt = regs::gpio_gpioa_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_odr_tt = regs::gpio_gpioa_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_bsrr_tt = regs::gpio_gpioa_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_lckr_tt = regs::gpio_gpioa_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_afrl_tt = regs::gpio_gpioa_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_afrh_tt = regs::gpio_gpioa_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_brr_tt = regs::gpio_gpioa_brr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_seccfgr_tt = regs::gpioa_gpioa_seccfgr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_privcfgr_tt = regs::gpdma_gpdma_privcfgr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_rcfglockr_tt = regs::gpio_gpioa_rcfglockr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_delayrl_tt = regs::gpio_gpioa_delayrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_delayrh_tt = regs::gpio_gpioa_delayrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_piocfgrl_tt = regs::gpio_gpioa_piocfgrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_piocfgrh_tt = regs::gpio_gpioa_piocfgrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_hwcfgr10_tt = regs::gpio_gpioa_hwcfgr10_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_hwcfgr9_tt = regs::gpio_gpioa_hwcfgr9_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_hwcfgr8_tt = regs::gpio_gpioa_hwcfgr8_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_hwcfgr7_tt = regs::gpio_gpioa_hwcfgr7_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_hwcfgr6_tt = regs::gpio_gpioa_hwcfgr6_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_hwcfgr5_tt = regs::gpio_gpioa_hwcfgr5_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_hwcfgr4_tt = regs::gpio_gpioa_hwcfgr4_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_hwcfgr3_tt = regs::gpio_gpioa_hwcfgr3_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_hwcfgr2_tt = regs::gpio_gpioa_hwcfgr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_hwcfgr1_tt = regs::gpio_gpioa_hwcfgr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_hwcfgr0_tt = regs::gpio_gpioa_hwcfgr0_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_verr_tt = regs::adc_adc_verr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_ipidr_tt = regs::gpio_gpioa_ipidr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioo_sidr_tt = regs::adc_adc_sidr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using gpioo_s_t =
    groov::group<"gpioo_s",
                 groov::mmio_bus<>,
                 gpioo_moder_tt<"gpioo_moder", baseaddress, 0x0>,
                 gpioo_otyper_tt<"gpioo_otyper", baseaddress, 0x4>,
                 gpioo_ospeedr_tt<"gpioo_ospeedr", baseaddress, 0x8>,
                 gpioo_pupdr_tt<"gpioo_pupdr", baseaddress, 0xc>,
                 gpioo_idr_tt<"gpioo_idr", baseaddress, 0x10>,
                 gpioo_odr_tt<"gpioo_odr", baseaddress, 0x14>,
                 gpioo_bsrr_tt<"gpioo_bsrr", baseaddress, 0x18>,
                 gpioo_lckr_tt<"gpioo_lckr", baseaddress, 0x1c>,
                 gpioo_afrl_tt<"gpioo_afrl", baseaddress, 0x20>,
                 gpioo_afrh_tt<"gpioo_afrh", baseaddress, 0x24>,
                 gpioo_brr_tt<"gpioo_brr", baseaddress, 0x28>,
                 gpioo_seccfgr_tt<"gpioo_seccfgr", baseaddress, 0x30>,
                 gpioo_privcfgr_tt<"gpioo_privcfgr", baseaddress, 0x34>,
                 gpioo_rcfglockr_tt<"gpioo_rcfglockr", baseaddress, 0x38>,
                 gpioo_delayrl_tt<"gpioo_delayrl", baseaddress, 0x40>,
                 gpioo_delayrh_tt<"gpioo_delayrh", baseaddress, 0x44>,
                 gpioo_piocfgrl_tt<"gpioo_piocfgrl", baseaddress, 0x48>,
                 gpioo_piocfgrh_tt<"gpioo_piocfgrh", baseaddress, 0x4c>,
                 gpioo_hwcfgr10_tt<"gpioo_hwcfgr10", baseaddress, 0x3c8>,
                 gpioo_hwcfgr9_tt<"gpioo_hwcfgr9", baseaddress, 0x3cc>,
                 gpioo_hwcfgr8_tt<"gpioo_hwcfgr8", baseaddress, 0x3d0>,
                 gpioo_hwcfgr7_tt<"gpioo_hwcfgr7", baseaddress, 0x3d4>,
                 gpioo_hwcfgr6_tt<"gpioo_hwcfgr6", baseaddress, 0x3d8>,
                 gpioo_hwcfgr5_tt<"gpioo_hwcfgr5", baseaddress, 0x3dc>,
                 gpioo_hwcfgr4_tt<"gpioo_hwcfgr4", baseaddress, 0x3e0>,
                 gpioo_hwcfgr3_tt<"gpioo_hwcfgr3", baseaddress, 0x3e4>,
                 gpioo_hwcfgr2_tt<"gpioo_hwcfgr2", baseaddress, 0x3e8>,
                 gpioo_hwcfgr1_tt<"gpioo_hwcfgr1", baseaddress, 0x3ec>,
                 gpioo_hwcfgr0_tt<"gpioo_hwcfgr0", baseaddress, 0x3f0>,
                 gpioo_verr_tt<"gpioo_verr", baseaddress, 0x3f4>,
                 gpioo_ipidr_tt<"gpioo_ipidr", baseaddress, 0x3f8>,
                 gpioo_sidr_tt<"gpioo_sidr", baseaddress, 0x3fc>>;

} // namespace gpioo_s
