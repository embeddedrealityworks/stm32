
namespace gpiop {
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

  template <std::uint32_t baseaddress>
  using gpiop_t =
    groov::group<"gpiop",
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
                 gpiop_brr_tt<"gpiop_brr", baseaddress, 0x28>>;

} // namespace gpiop
