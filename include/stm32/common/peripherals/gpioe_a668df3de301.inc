
namespace gpioex {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioe_moder_tt = regs::gpio_gpioa_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioe_otyper_tt = regs::gpio_gpioa_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioe_ospeedr_tt = regs::gpio_gpioa_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioe_pupdr_tt = regs::gpio_gpioa_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioe_idr_tt = regs::gpioa_gpioa_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioe_odr_tt = regs::gpio_gpioa_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioe_bsrr_tt = regs::gpioa_gpioa_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioe_lckr_tt = regs::gpio_gpioa_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioe_afrl_tt = regs::gpio_gpioa_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioe_afrh_tt = regs::gpio_gpioa_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioe_brr_tt = regs::gpioa_gpioa_brr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioe_hslvr_tt = regs::gpio_gpioa_hslvr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioe_seccfgr_tt = regs::gpioa_gpioa_seccfgr_v1_tt<name, baseaddress, offset>;

  template <stdx::ct_string name, std::uint32_t baseaddress>
  using gpioex_t =
    groov::group<name,
                 groov::mmio_bus<>,
                 gpioe_moder_tt<"gpioe_moder", baseaddress, 0x0>,
                 gpioe_otyper_tt<"gpioe_otyper", baseaddress, 0x4>,
                 gpioe_ospeedr_tt<"gpioe_ospeedr", baseaddress, 0x8>,
                 gpioe_pupdr_tt<"gpioe_pupdr", baseaddress, 0xc>,
                 gpioe_idr_tt<"gpioe_idr", baseaddress, 0x10>,
                 gpioe_odr_tt<"gpioe_odr", baseaddress, 0x14>,
                 gpioe_bsrr_tt<"gpioe_bsrr", baseaddress, 0x18>,
                 gpioe_lckr_tt<"gpioe_lckr", baseaddress, 0x1c>,
                 gpioe_afrl_tt<"gpioe_afrl", baseaddress, 0x20>,
                 gpioe_afrh_tt<"gpioe_afrh", baseaddress, 0x24>,
                 gpioe_brr_tt<"gpioe_brr", baseaddress, 0x28>,
                 gpioe_hslvr_tt<"gpioe_hslvr", baseaddress, 0x2c>,
                 gpioe_seccfgr_tt<"gpioe_seccfgr", baseaddress, 0x30>>;

} // namespace gpioex
