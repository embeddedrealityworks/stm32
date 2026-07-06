
namespace gpiox {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpio_moder_tt = regs::gpio_moder_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpio_otyper_tt = regs::gpio_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpio_ospeedr_tt = regs::gpio_ospeedr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpio_pupdr_tt = regs::gpio_pupdr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpio_idr_tt = regs::gpio_idr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpio_odr_tt = regs::gpio_odr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpio_bsrr_tt = regs::gpio_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpio_lckr_tt = regs::gpio_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpio_afrl_tt = regs::gpio_afrl_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpio_afrh_tt = regs::gpio_afrh_v2_tt<name, baseaddress, offset>;

  template <stdx::ct_string name, std::uint32_t baseaddress>
  using gpiox_t =
    groov::group<name,
                 groov::mmio_bus<>,
                 gpio_moder_tt<"gpio_moder", baseaddress, 0x0>,
                 gpio_otyper_tt<"gpio_otyper", baseaddress, 0x4>,
                 gpio_ospeedr_tt<"gpio_ospeedr", baseaddress, 0x8>,
                 gpio_pupdr_tt<"gpio_pupdr", baseaddress, 0xc>,
                 gpio_idr_tt<"gpio_idr", baseaddress, 0x10>,
                 gpio_odr_tt<"gpio_odr", baseaddress, 0x14>,
                 gpio_bsrr_tt<"gpio_bsrr", baseaddress, 0x18>,
                 gpio_lckr_tt<"gpio_lckr", baseaddress, 0x1c>,
                 gpio_afrl_tt<"gpio_afrl", baseaddress, 0x20>,
                 gpio_afrh_tt<"gpio_afrh", baseaddress, 0x24>>;

} // namespace gpiox
