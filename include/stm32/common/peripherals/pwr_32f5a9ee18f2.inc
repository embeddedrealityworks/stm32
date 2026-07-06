
namespace pwr {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr_tt = regs::pwr_cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using csr_tt = regs::pwr_csr_v6_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using pwr_t =
    groov::group<"pwr",
                 groov::mmio_bus<>,
                 cr_tt<"cr", baseaddress, 0x0>,
                 csr_tt<"csr", baseaddress, 0x4>>;

} // namespace pwr
