
namespace spi {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi_sspcr1_tt = regs::spi_spi_cr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi_sspcr2_tt = regs::spi_spi_cr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi_sspsr_tt = regs::spi_spi_sr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi_sspdr_tt = regs::spi_spi_dr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi_sspcrcpr_tt = regs::spi_spi_crcpr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi_ssprxcrcr_tt = regs::spi_spi_rxcrcr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using spi_ssptxcrcr_tt = regs::spi_spi_ssptxcrcr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using spi_t =
    groov::group<"spi",
                 groov::mmio_bus<>,
                 spi_sspcr1_tt<"spi_sspcr1", baseaddress, 0x0>,
                 spi_sspcr2_tt<"spi_sspcr2", baseaddress, 0x4>,
                 spi_sspsr_tt<"spi_sspsr", baseaddress, 0x8>,
                 spi_sspdr_tt<"spi_sspdr", baseaddress, 0xc>,
                 spi_sspcrcpr_tt<"spi_sspcrcpr", baseaddress, 0x10>,
                 spi_ssprxcrcr_tt<"spi_ssprxcrcr", baseaddress, 0x14>,
                 spi_ssptxcrcr_tt<"spi_ssptxcrcr", baseaddress, 0x18>>;

} // namespace spi
