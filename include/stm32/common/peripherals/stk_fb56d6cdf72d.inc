
namespace stk {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ctrl_tt = regs::stk_csr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using load__tt = regs::stk_rvr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using val_tt = regs::stk_cvr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using calib_tt = regs::stk_calib_v2_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using stk_t =
    groov::group<"stk",
                 groov::mmio_bus<>,
                 ctrl_tt<"ctrl", baseaddress, 0x0>,
                 load__tt<"load_", baseaddress, 0x4>,
                 val_tt<"val", baseaddress, 0x8>,
                 calib_tt<"calib", baseaddress, 0xc>>;

} // namespace stk
