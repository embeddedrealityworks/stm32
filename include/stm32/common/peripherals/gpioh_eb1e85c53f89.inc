
namespace gpiohx {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_moder_tt = regs::gpio_gpioa_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_otyper_tt = regs::gpio_gpioa_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_ospeedr_tt = regs::gpio_gpioa_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_pupdr_tt = regs::gpio_gpioa_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_idr_tt = regs::gpioa_gpioa_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_odr_tt = regs::gpio_gpioa_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_bsrr_tt = regs::gpioa_gpioa_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_lckr_tt = regs::gpio_gpioa_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_afrl_tt = regs::gpio_gpioa_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_afrh_tt = regs::gpio_gpioa_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_brr_tt = regs::gpioa_gpioa_brr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_hslvr_tt = regs::gpio_gpioa_hslvr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioh_seccfgr_tt = regs::gpioa_gpioa_seccfgr_v1_tt<name, baseaddress, offset>;

  template <stdx::ct_string name, std::uint32_t baseaddress>
  using gpiohx_t =
    groov::group<name,
                 groov::mmio_bus<>,
                 gpioh_moder_tt<"gpioh_moder", baseaddress, 0x0>,
                 gpioh_otyper_tt<"gpioh_otyper", baseaddress, 0x4>,
                 gpioh_ospeedr_tt<"gpioh_ospeedr", baseaddress, 0x8>,
                 gpioh_pupdr_tt<"gpioh_pupdr", baseaddress, 0xc>,
                 gpioh_idr_tt<"gpioh_idr", baseaddress, 0x10>,
                 gpioh_odr_tt<"gpioh_odr", baseaddress, 0x14>,
                 gpioh_bsrr_tt<"gpioh_bsrr", baseaddress, 0x18>,
                 gpioh_lckr_tt<"gpioh_lckr", baseaddress, 0x1c>,
                 gpioh_afrl_tt<"gpioh_afrl", baseaddress, 0x20>,
                 gpioh_afrh_tt<"gpioh_afrh", baseaddress, 0x24>,
                 gpioh_brr_tt<"gpioh_brr", baseaddress, 0x28>,
                 gpioh_hslvr_tt<"gpioh_hslvr", baseaddress, 0x2c>,
                 gpioh_seccfgr_tt<"gpioh_seccfgr", baseaddress, 0x30>>;

} // namespace gpiohx
