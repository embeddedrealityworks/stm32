
namespace spdifrx {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr_tt = regs::spdifrx_cr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using imr_tt = regs::spdif_rx_imr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using sr_tt = regs::spdif_rx_sr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ifcr_tt = regs::spdif_rx_ifcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dr_00_tt = regs::spdif_rx_dr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using csr_tt = regs::spdif_rx_csr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dir_tt = regs::spdif_rx_dir_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using verr_tt = regs::iwdg_verr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using idr_tt = regs::dmamux_dmamux_ipidr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using sidr_tt = regs::iwdg_sidr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dr_01_tt = regs::spdifrx_dr_01_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dr_10_tt = regs::spdifrx_dr_10_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using spdifrx_t =
    groov::group<"spdifrx",
                 groov::mmio_bus<>,
                 cr_tt<"cr", baseaddress, 0x0>,
                 imr_tt<"imr", baseaddress, 0x4>,
                 sr_tt<"sr", baseaddress, 0x8>,
                 ifcr_tt<"ifcr", baseaddress, 0xc>,
                 dr_00_tt<"dr_00", baseaddress, 0x10>,
                 csr_tt<"csr", baseaddress, 0x14>,
                 dir_tt<"dir", baseaddress, 0x18>,
                 verr_tt<"verr", baseaddress, 0x3f4>,
                 idr_tt<"idr", baseaddress, 0x3f8>,
                 sidr_tt<"sidr", baseaddress, 0x3fc>,
                 dr_01_tt<"dr_01", baseaddress, 0x10>,
                 dr_10_tt<"dr_10", baseaddress, 0x10>>;

} // namespace spdifrx
