
namespace vrefbuf {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using vrefbuf_csr_tt = regs::vrefbuf_vrefbuf_csr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using vrefbuf_ccr_tt = regs::vrefbuf_ccr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using vrefbuf_t =
    groov::group<"vrefbuf",
                 groov::mmio_bus<>,
                 vrefbuf_csr_tt<"vrefbuf_csr", baseaddress, 0x0>,
                 vrefbuf_ccr_tt<"vrefbuf_ccr", baseaddress, 0x4>>;

} // namespace vrefbuf
