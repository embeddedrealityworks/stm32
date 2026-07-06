
namespace fmcx {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_bcr1_tt = regs::fmc_bcr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_bcr2_tt = regs::fmc_bcr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_bcr3_tt = regs::fmc_bcr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_bcr4_tt = regs::fmc_bcr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_btr1_tt = regs::fmc_btr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_btr2_tt = regs::fmc_btr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_btr3_tt = regs::fmc_btr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_btr4_tt = regs::fmc_btr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_pcr_tt = regs::fsmc_pcr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_sr_tt = regs::fsmc_sr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_pmem_tt = regs::fmc_pmem_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_patt_tt = regs::fmc_patt_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_eccr_tt = regs::fmc_eccr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_bwtr1_tt = regs::fsmc_bwtr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_bwtr2_tt = regs::fsmc_bwtr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_bwtr3_tt = regs::fsmc_bwtr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fmc_bwtr4_tt = regs::fsmc_bwtr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using pcscntr_tt = regs::fmc_pcscntr_v1_tt<name, baseaddress, offset>;

  template <stdx::ct_string name, std::uint32_t baseaddress>
  using fmcx_t =
    groov::group<name,
                 groov::mmio_bus<>,
                 fmc_bcr1_tt<"fmc_bcr1", baseaddress, 0x0>,
                 fmc_bcr2_tt<"fmc_bcr2", baseaddress, 0x8>,
                 fmc_bcr3_tt<"fmc_bcr3", baseaddress, 0x10>,
                 fmc_bcr4_tt<"fmc_bcr4", baseaddress, 0x18>,
                 fmc_btr1_tt<"fmc_btr1", baseaddress, 0x4>,
                 fmc_btr2_tt<"fmc_btr2", baseaddress, 0xc>,
                 fmc_btr3_tt<"fmc_btr3", baseaddress, 0x14>,
                 fmc_btr4_tt<"fmc_btr4", baseaddress, 0x1c>,
                 fmc_pcr_tt<"fmc_pcr", baseaddress, 0x80>,
                 fmc_sr_tt<"fmc_sr", baseaddress, 0x84>,
                 fmc_pmem_tt<"fmc_pmem", baseaddress, 0x88>,
                 fmc_patt_tt<"fmc_patt", baseaddress, 0x8c>,
                 fmc_eccr_tt<"fmc_eccr", baseaddress, 0x94>,
                 fmc_bwtr1_tt<"fmc_bwtr1", baseaddress, 0x104>,
                 fmc_bwtr2_tt<"fmc_bwtr2", baseaddress, 0x10c>,
                 fmc_bwtr3_tt<"fmc_bwtr3", baseaddress, 0x114>,
                 fmc_bwtr4_tt<"fmc_bwtr4", baseaddress, 0x11c>,
                 pcscntr_tt<"pcscntr", baseaddress, 0x20>>;

} // namespace fmcx
