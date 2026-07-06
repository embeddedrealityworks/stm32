
namespace gpioa {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using moder_tt = regs::gpio_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using otyper_tt = regs::gpio_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ospeedr_tt = regs::gpio_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using pupdr_tt = regs::gpio_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using idr_tt = regs::gpio_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using odr_tt = regs::gpio_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using bsrr_tt = regs::gpio_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using lckr_tt = regs::gpio_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using afrl_tt = regs::gpio_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using afrh_tt = regs::gpio_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using brr_tt = regs::gpio_brr_v2_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using gpioa_t =
    groov::group<"gpioa",
                 groov::mmio_bus<>,
                 moder_tt<"moder", baseaddress, 0x0>,
                 otyper_tt<"otyper", baseaddress, 0x4>,
                 ospeedr_tt<"ospeedr", baseaddress, 0x8>,
                 pupdr_tt<"pupdr", baseaddress, 0xc>,
                 idr_tt<"idr", baseaddress, 0x10>,
                 odr_tt<"odr", baseaddress, 0x14>,
                 bsrr_tt<"bsrr", baseaddress, 0x18>,
                 lckr_tt<"lckr", baseaddress, 0x1c>,
                 afrl_tt<"afrl", baseaddress, 0x20>,
                 afrh_tt<"afrh", baseaddress, 0x24>,
                 brr_tt<"brr", baseaddress, 0x28>>;

} // namespace gpioa

namespace gpiob {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using moder_tt = regs::gpio_moder_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using otyper_tt = regs::gpio_otyper_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ospeedr_tt = regs::gpio_ospeedr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using pupdr_tt = regs::gpio_pupdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using idr_tt = regs::gpio_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using odr_tt = regs::gpio_odr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using bsrr_tt = regs::gpio_bsrr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using lckr_tt = regs::gpio_lckr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using afrl_tt = regs::gpio_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using afrh_tt = regs::gpio_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using brr_tt = regs::gpio_brr_v2_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using gpiob_t =
    groov::group<"gpiob",
                 groov::mmio_bus<>,
                 moder_tt<"moder", baseaddress, 0x0>,
                 otyper_tt<"otyper", baseaddress, 0x4>,
                 ospeedr_tt<"ospeedr", baseaddress, 0x8>,
                 pupdr_tt<"pupdr", baseaddress, 0xc>,
                 idr_tt<"idr", baseaddress, 0x10>,
                 odr_tt<"odr", baseaddress, 0x14>,
                 bsrr_tt<"bsrr", baseaddress, 0x18>,
                 lckr_tt<"lckr", baseaddress, 0x1c>,
                 afrl_tt<"afrl", baseaddress, 0x20>,
                 afrh_tt<"afrh", baseaddress, 0x24>,
                 brr_tt<"brr", baseaddress, 0x28>>;

} // namespace gpiob

namespace gpioc {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using moder_tt = regs::gpio_moder_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using otyper_tt = regs::gpio_otyper_v4_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ospeedr_tt = regs::gpio_ospeedr_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using pupdr_tt = regs::gpio_pupdr_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using idr_tt = regs::gpio_idr_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using odr_tt = regs::gpio_odr_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using bsrr_tt = regs::gpio_bsrr_v4_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using lckr_tt = regs::gpio_lckr_v4_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using afrl_tt = regs::gpio_afrl_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using afrh_tt = regs::gpio_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using brr_tt = regs::gpio_brr_v5_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using gpioc_t =
    groov::group<"gpioc",
                 groov::mmio_bus<>,
                 moder_tt<"moder", baseaddress, 0x0>,
                 otyper_tt<"otyper", baseaddress, 0x4>,
                 ospeedr_tt<"ospeedr", baseaddress, 0x8>,
                 pupdr_tt<"pupdr", baseaddress, 0xc>,
                 idr_tt<"idr", baseaddress, 0x10>,
                 odr_tt<"odr", baseaddress, 0x14>,
                 bsrr_tt<"bsrr", baseaddress, 0x18>,
                 lckr_tt<"lckr", baseaddress, 0x1c>,
                 afrl_tt<"afrl", baseaddress, 0x20>,
                 afrh_tt<"afrh", baseaddress, 0x24>,
                 brr_tt<"brr", baseaddress, 0x28>>;

} // namespace gpioc

namespace gpioh {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using moder_tt = regs::gpio_moder_v6_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using otyper_tt = regs::gpio_otyper_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ospeedr_tt = regs::gpio_ospeedr_v6_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using pupdr_tt = regs::gpio_pupdr_v6_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using idr_tt = regs::gpio_idr_v6_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using odr_tt = regs::gpio_odr_v6_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using bsrr_tt = regs::gpio_bsrr_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using lckr_tt = regs::gpio_lckr_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using afrl_tt = regs::gpio_afrl_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using afrh_tt = regs::gpio_afrh_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using brr_tt = regs::gpio_brr_v6_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using gpioh_t =
    groov::group<"gpioh",
                 groov::mmio_bus<>,
                 moder_tt<"moder", baseaddress, 0x0>,
                 otyper_tt<"otyper", baseaddress, 0x4>,
                 ospeedr_tt<"ospeedr", baseaddress, 0x8>,
                 pupdr_tt<"pupdr", baseaddress, 0xc>,
                 idr_tt<"idr", baseaddress, 0x10>,
                 odr_tt<"odr", baseaddress, 0x14>,
                 bsrr_tt<"bsrr", baseaddress, 0x18>,
                 lckr_tt<"lckr", baseaddress, 0x1c>,
                 afrl_tt<"afrl", baseaddress, 0x20>,
                 afrh_tt<"afrh", baseaddress, 0x24>,
                 brr_tt<"brr", baseaddress, 0x28>>;

} // namespace gpioh
