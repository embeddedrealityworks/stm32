
namespace dbgmcu {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using idcode_tt = regs::dbg_idcode_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr_tt = regs::dbg_dbgmcu_cr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using apb1_fz_tt = regs::dbgmcu_apb1_fz_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using apb2_fz_tt = regs::dbgmcu_apb2_fz_v4_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using dbgmcu_t =
    groov::group<"dbgmcu",
                 groov::mmio_bus<>,
                 idcode_tt<"idcode", baseaddress, 0x0>,
                 cr_tt<"cr", baseaddress, 0x4>,
                 apb1_fz_tt<"apb1_fz", baseaddress, 0x8>,
                 apb2_fz_tt<"apb2_fz", baseaddress, 0xc>>;

} // namespace dbgmcu
