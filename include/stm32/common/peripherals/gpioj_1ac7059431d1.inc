
namespace gpiojx {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioj_moder_tt = regs::gpio_gpioa_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioj_otyper_tt = regs::gpio_gpioa_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioj_ospeedr_tt = regs::gpio_gpioa_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioj_pupdr_tt = regs::gpio_gpioa_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioj_idr_tt = regs::gpioa_gpioa_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioj_odr_tt = regs::gpio_gpioa_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioj_bsrr_tt = regs::gpioa_gpioa_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioj_lckr_tt = regs::gpio_gpioa_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioj_afrl_tt = regs::gpio_gpioa_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioj_afrh_tt = regs::gpio_gpioa_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioj_brr_tt = regs::gpioa_gpioa_brr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioj_hslvr_tt = regs::gpio_gpioa_hslvr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using gpioj_seccfgr_tt = regs::gpioa_gpioa_seccfgr_v1_tt<name, baseaddress, offset>;

  template <stdx::ct_string name, std::uint32_t baseaddress>
  using gpiojx_t =
    groov::group<name,
                 groov::mmio_bus<>,
                 gpioj_moder_tt<"gpioj_moder", baseaddress, 0x0>,
                 gpioj_otyper_tt<"gpioj_otyper", baseaddress, 0x4>,
                 gpioj_ospeedr_tt<"gpioj_ospeedr", baseaddress, 0x8>,
                 gpioj_pupdr_tt<"gpioj_pupdr", baseaddress, 0xc>,
                 gpioj_idr_tt<"gpioj_idr", baseaddress, 0x10>,
                 gpioj_odr_tt<"gpioj_odr", baseaddress, 0x14>,
                 gpioj_bsrr_tt<"gpioj_bsrr", baseaddress, 0x18>,
                 gpioj_lckr_tt<"gpioj_lckr", baseaddress, 0x1c>,
                 gpioj_afrl_tt<"gpioj_afrl", baseaddress, 0x20>,
                 gpioj_afrh_tt<"gpioj_afrh", baseaddress, 0x24>,
                 gpioj_brr_tt<"gpioj_brr", baseaddress, 0x28>,
                 gpioj_hslvr_tt<"gpioj_hslvr", baseaddress, 0x2c>,
                 gpioj_seccfgr_tt<"gpioj_seccfgr", baseaddress, 0x30>>;

} // namespace gpiojx
