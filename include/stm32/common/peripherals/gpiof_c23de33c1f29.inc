
namespace gpiof {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiof_moder_tt = regs::gpio_gpioa_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiof_otyper_tt = regs::gpio_gpioa_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiof_ospeedr_tt = regs::gpio_gpioa_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiof_pupdr_tt = regs::gpio_gpioa_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiof_idr_tt = regs::gpioa_gpioa_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiof_odr_tt = regs::gpio_gpioa_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiof_bsrr_tt = regs::gpioa_gpioa_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiof_lckr_tt = regs::gpio_gpioa_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiof_afrl_tt = regs::gpio_gpioa_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiof_afrh_tt = regs::gpio_gpioa_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpiof_brr_tt = regs::gpioa_gpioa_brr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using gpiof_t =
    groov::group<"gpiof",
                 groov::mmio_bus<>,
                 gpiof_moder_tt<"gpiof_moder", baseaddress, 0x0>,
                 gpiof_otyper_tt<"gpiof_otyper", baseaddress, 0x4>,
                 gpiof_ospeedr_tt<"gpiof_ospeedr", baseaddress, 0x8>,
                 gpiof_pupdr_tt<"gpiof_pupdr", baseaddress, 0xc>,
                 gpiof_idr_tt<"gpiof_idr", baseaddress, 0x10>,
                 gpiof_odr_tt<"gpiof_odr", baseaddress, 0x14>,
                 gpiof_bsrr_tt<"gpiof_bsrr", baseaddress, 0x18>,
                 gpiof_lckr_tt<"gpiof_lckr", baseaddress, 0x1c>,
                 gpiof_afrl_tt<"gpiof_afrl", baseaddress, 0x20>,
                 gpiof_afrh_tt<"gpiof_afrh", baseaddress, 0x24>,
                 gpiof_brr_tt<"gpiof_brr", baseaddress, 0x28>>;

} // namespace gpiof
