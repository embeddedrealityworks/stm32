
namespace xspimx {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspim_cr_tt = regs::octospim_octospim_cr_v1_tt<name, baseaddress, offset>;

  template <stdx::ct_string name, std::uint32_t baseaddress>
  using xspimx_t =
    groov::group<name,
                 groov::mmio_bus<>,
                 xspim_cr_tt<"xspim_cr", baseaddress, 0x0>>;

} // namespace xspimx
