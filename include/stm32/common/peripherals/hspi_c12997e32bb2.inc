
namespace hspix {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_cr_tt = regs::hspi_hspi_cr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_dcr1_tt = regs::octospi_octospi_dcr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_dcr2_tt = regs::octospi_octospi_dcr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_dcr3_tt = regs::octospi1_octospi1_dcr3_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_dcr4_tt = regs::octospi_octospi_dcr4_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_sr_tt = regs::xspi_xspi_sr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_fcr_tt = regs::octospi_octospi_fcr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_dlr_tt = regs::octospi_octospi_dlr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_ar_tt = regs::octospi_octospi_ar_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_dr_tt = regs::octospi_octospi_dr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_psmkr_tt = regs::octospi_octospi_psmkr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_psmar_tt = regs::octospi_octospi_psmar_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_pir_tt = regs::octospi_octospi_pir_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_ccr_tt = regs::octospi_octospi_ccr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_tcr_tt = regs::octospi_octospi_tcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_ir_tt = regs::octospi_octospi_ir_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_abr_tt = regs::octospi_octospi_abr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_lptr_tt = regs::octospi_octospi_lptr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_wpccr_tt = regs::octospi_octospi_ccr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_wptcr_tt = regs::octospi_octospi_tcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_wpir_tt = regs::octospi_octospi_ir_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_wpabr_tt = regs::octospi_octospi_abr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_wccr_tt = regs::octospi_octospi_ccr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_wtcr_tt = regs::octospi_octospi_wtcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_wir_tt = regs::octospi_octospi_ir_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_wabr_tt = regs::octospi_octospi_abr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_hlcr_tt = regs::octospi_octospi_hlcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_calfcr_tt = regs::xspi_xspi_calfcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_calmr_tt = regs::xspi_xspi_calmr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_calsor_tt = regs::xspi_xspi_calmr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using hspi_calsir_tt = regs::xspi_xspi_calmr_v1_tt<name, baseaddress, offset>;

  template <stdx::ct_string name, std::uint32_t baseaddress>
  using hspix_t =
    groov::group<name,
                 groov::mmio_bus<>,
                 hspi_cr_tt<"hspi_cr", baseaddress, 0x0>,
                 hspi_dcr1_tt<"hspi_dcr1", baseaddress, 0x8>,
                 hspi_dcr2_tt<"hspi_dcr2", baseaddress, 0xc>,
                 hspi_dcr3_tt<"hspi_dcr3", baseaddress, 0x10>,
                 hspi_dcr4_tt<"hspi_dcr4", baseaddress, 0x14>,
                 hspi_sr_tt<"hspi_sr", baseaddress, 0x20>,
                 hspi_fcr_tt<"hspi_fcr", baseaddress, 0x24>,
                 hspi_dlr_tt<"hspi_dlr", baseaddress, 0x40>,
                 hspi_ar_tt<"hspi_ar", baseaddress, 0x48>,
                 hspi_dr_tt<"hspi_dr", baseaddress, 0x50>,
                 hspi_psmkr_tt<"hspi_psmkr", baseaddress, 0x80>,
                 hspi_psmar_tt<"hspi_psmar", baseaddress, 0x88>,
                 hspi_pir_tt<"hspi_pir", baseaddress, 0x90>,
                 hspi_ccr_tt<"hspi_ccr", baseaddress, 0x100>,
                 hspi_tcr_tt<"hspi_tcr", baseaddress, 0x108>,
                 hspi_ir_tt<"hspi_ir", baseaddress, 0x110>,
                 hspi_abr_tt<"hspi_abr", baseaddress, 0x120>,
                 hspi_lptr_tt<"hspi_lptr", baseaddress, 0x130>,
                 hspi_wpccr_tt<"hspi_wpccr", baseaddress, 0x140>,
                 hspi_wptcr_tt<"hspi_wptcr", baseaddress, 0x148>,
                 hspi_wpir_tt<"hspi_wpir", baseaddress, 0x150>,
                 hspi_wpabr_tt<"hspi_wpabr", baseaddress, 0x160>,
                 hspi_wccr_tt<"hspi_wccr", baseaddress, 0x180>,
                 hspi_wtcr_tt<"hspi_wtcr", baseaddress, 0x188>,
                 hspi_wir_tt<"hspi_wir", baseaddress, 0x190>,
                 hspi_wabr_tt<"hspi_wabr", baseaddress, 0x1a0>,
                 hspi_hlcr_tt<"hspi_hlcr", baseaddress, 0x200>,
                 hspi_calfcr_tt<"hspi_calfcr", baseaddress, 0x210>,
                 hspi_calmr_tt<"hspi_calmr", baseaddress, 0x218>,
                 hspi_calsor_tt<"hspi_calsor", baseaddress, 0x220>,
                 hspi_calsir_tt<"hspi_calsir", baseaddress, 0x228>>;

} // namespace hspix
