
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
  using gpioc_idr_tt = regs::gpioa_gpioa_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_odr_tt = regs::gpio_gpioa_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioc_bsrr_tt = regs::gpioa_gpioa_bsrr_v1_tt<name, baseaddress, offset>;
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
  using gpioc_brr_tt = regs::gpioa_gpioa_brr_v1_tt<name, baseaddress, offset>;

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
                 gpioc_brr_tt<"gpioc_brr", baseaddress, 0x28>>;

} // namespace gpioc
