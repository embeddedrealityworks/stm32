
namespace sdmmcx {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using power_tt = regs::sdmmc_sdmmc_power_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using clkcr_tt = regs::sdmmc_sdmmc_clkcr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using argr_tt = regs::sdio_arg_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cmdr_tt = regs::sdmmc_sdmmc_cmdr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using resp1r_tt = regs::sdio_respi1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using resp2r_tt = regs::sdio_resp2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using resp3r_tt = regs::sdio_resp3_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using resp4r_tt = regs::sdio_resp4_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dtimer_tt = regs::sdio_dtimer_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dlenr_tt = regs::sdio_dlen_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dctrl_tt = regs::sdmmc_sdmmc_dctrl_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dcntr_tt = regs::sdio_dcount_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using star_tt = regs::sdmmc_sdmmc_star_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using icr_tt = regs::sdmmc_sdmmc_icr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using maskr_tt = regs::sdmmc_sdmmc_maskr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using acktimer_tt = regs::sdmmc_sdmmc_acktimer_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using idmactrlr_tt = regs::sdmmc_sdmmc_idmactrlr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using idmabsizer_tt = regs::sdmmc_sdmmc_idmabsizer_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using idmabase0r_tt = regs::sdmmc_sdmmc_idmabase0r_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using idmabase1r_tt = regs::sdmmc_sdmmc_idmabase1r_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using fifor_tt = regs::sdmmc_sdmmc_fifor_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ver_tt = regs::iwdg_verr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using id_tt = regs::sdmmc_id_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using respcmdr_tt = regs::sdio_respcmd_v1_tt<name, baseaddress, offset>;

  template <stdx::ct_string name, std::uint32_t baseaddress>
  using sdmmcx_t =
    groov::group<name,
                 groov::mmio_bus<>,
                 power_tt<"power", baseaddress, 0x0>,
                 clkcr_tt<"clkcr", baseaddress, 0x4>,
                 argr_tt<"argr", baseaddress, 0x8>,
                 cmdr_tt<"cmdr", baseaddress, 0xc>,
                 resp1r_tt<"resp1r", baseaddress, 0x14>,
                 resp2r_tt<"resp2r", baseaddress, 0x18>,
                 resp3r_tt<"resp3r", baseaddress, 0x1c>,
                 resp4r_tt<"resp4r", baseaddress, 0x20>,
                 dtimer_tt<"dtimer", baseaddress, 0x24>,
                 dlenr_tt<"dlenr", baseaddress, 0x28>,
                 dctrl_tt<"dctrl", baseaddress, 0x2c>,
                 dcntr_tt<"dcntr", baseaddress, 0x30>,
                 star_tt<"star", baseaddress, 0x34>,
                 icr_tt<"icr", baseaddress, 0x38>,
                 maskr_tt<"maskr", baseaddress, 0x3c>,
                 acktimer_tt<"acktimer", baseaddress, 0x40>,
                 idmactrlr_tt<"idmactrlr", baseaddress, 0x50>,
                 idmabsizer_tt<"idmabsizer", baseaddress, 0x54>,
                 idmabase0r_tt<"idmabase0r", baseaddress, 0x58>,
                 idmabase1r_tt<"idmabase1r", baseaddress, 0x5c>,
                 fifor_tt<"fifor", baseaddress, 0x80>,
                 ver_tt<"ver", baseaddress, 0x3f4>,
                 id_tt<"id", baseaddress, 0x3f8>,
                 respcmdr_tt<"respcmdr", baseaddress, 0x10>>;

} // namespace sdmmcx
