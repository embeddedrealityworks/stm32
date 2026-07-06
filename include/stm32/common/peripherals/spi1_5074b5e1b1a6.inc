
namespace spi1 {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi1_cr1_tt = regs::spi_spi_cr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi1_cr2_tt = regs::spi_spi_cr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi1_sr_tt = regs::spi_spi_sr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi1_dr_tt = regs::spi_spi_dr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi1_crcpr_tt = regs::spi_spi_crcpr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi1_rxcrcr_tt = regs::spi_spi_rxcrcr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi1_txcrcr_tt = regs::spi_spi_txcrcr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi1_i2scfgr_tt = regs::spi2_spi2_i2scfgr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi1_i2spr_tt = regs::spi_spi_i2spr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using spi1_t =
    groov::group<"spi1",
                 groov::mmio_bus<>,
                 spi1_cr1_tt<"spi1_cr1", baseaddress, 0x0>,
                 spi1_cr2_tt<"spi1_cr2", baseaddress, 0x4>,
                 spi1_sr_tt<"spi1_sr", baseaddress, 0x8>,
                 spi1_dr_tt<"spi1_dr", baseaddress, 0xc>,
                 spi1_crcpr_tt<"spi1_crcpr", baseaddress, 0x10>,
                 spi1_rxcrcr_tt<"spi1_rxcrcr", baseaddress, 0x14>,
                 spi1_txcrcr_tt<"spi1_txcrcr", baseaddress, 0x18>,
                 spi1_i2scfgr_tt<"spi1_i2scfgr", baseaddress, 0x1c>,
                 spi1_i2spr_tt<"spi1_i2spr", baseaddress, 0x20>>;

} // namespace spi1
