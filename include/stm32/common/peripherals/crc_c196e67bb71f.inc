
namespace crc {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dr_tt = regs::crc_dr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using idr_tt = regs::crc_idr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr_tt = regs::crc_cr_v2_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using crc_t =
    groov::group<"crc",
                 groov::mmio_bus<>,
                 dr_tt<"dr", baseaddress, 0x0>,
                 idr_tt<"idr", baseaddress, 0x4>,
                 cr_tt<"cr", baseaddress, 0x8>>;

} // namespace crc
