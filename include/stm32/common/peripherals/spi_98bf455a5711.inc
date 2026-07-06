
namespace spi3 {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spix_cr1_tt = regs::spi_spi_cr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spix_cr2_tt = regs::spi_spi_cr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spix_sr_tt = regs::spi_spi_sr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spix_dr_tt = regs::spi_spi_dr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spix_crcpr_tt = regs::spi_spi_crcpr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spix_rxcrcr_tt = regs::spi_spi_rxcrcr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spix_txcrcr_tt = regs::spi_spi_txcrcr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spix_i2scfgr_tt = regs::spi_spi_i2scfgr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spix_i2spr_tt = regs::spi_spi_i2spr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using spi3_t =
    groov::group<"spi3",
                 groov::mmio_bus<>,
                 spix_cr1_tt<"spix_cr1", baseaddress, 0x0>,
                 spix_cr2_tt<"spix_cr2", baseaddress, 0x4>,
                 spix_sr_tt<"spix_sr", baseaddress, 0x8>,
                 spix_dr_tt<"spix_dr", baseaddress, 0xc>,
                 spix_crcpr_tt<"spix_crcpr", baseaddress, 0x10>,
                 spix_rxcrcr_tt<"spix_rxcrcr", baseaddress, 0x14>,
                 spix_txcrcr_tt<"spix_txcrcr", baseaddress, 0x18>,
                 spix_i2scfgr_tt<"spix_i2scfgr", baseaddress, 0x1c>,
                 spix_i2spr_tt<"spix_i2spr", baseaddress, 0x20>>;

} // namespace spi3
