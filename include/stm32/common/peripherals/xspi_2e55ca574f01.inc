
namespace xspix {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_cr_tt = regs::xspi_xspi_cr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_dcr1_tt = regs::xspi_xspi_dcr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_dcr2_tt = regs::octospi_octospi_dcr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_dcr3_tt = regs::octospi1_octospi1_dcr3_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_dcr4_tt = regs::octospi_octospi_dcr4_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_sr_tt = regs::xspi_xspi_sr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_fcr_tt = regs::octospi_octospi_fcr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_dlr_tt = regs::octospi_octospi_dlr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_ar_tt = regs::octospi_octospi_ar_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_dr_tt = regs::octospi_octospi_dr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_psmkr_tt = regs::octospi_octospi_psmkr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_psmar_tt = regs::octospi_octospi_psmar_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_pir_tt = regs::octospi_octospi_pir_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_ccr_tt = regs::octospi_octospi_ccr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_tcr_tt = regs::octospi_octospi_tcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_ir_tt = regs::octospi_octospi_ir_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_abr_tt = regs::octospi_octospi_abr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_lptr_tt = regs::octospi_octospi_lptr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_wpccr_tt = regs::octospi_octospi_ccr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_wptcr_tt = regs::octospi_octospi_tcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_wpir_tt = regs::octospi_octospi_ir_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_wpabr_tt = regs::octospi_octospi_abr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_wccr_tt = regs::octospi_octospi_ccr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_wtcr_tt = regs::octospi_octospi_wtcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_wir_tt = regs::octospi_octospi_ir_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_wabr_tt = regs::octospi_octospi_abr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_hlcr_tt = regs::octospi_octospi_hlcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_calfcr_tt = regs::xspi_xspi_calfcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_calmr_tt = regs::xspi_xspi_calmr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_calsor_tt = regs::xspi_xspi_calmr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using xspi_calsir_tt = regs::xspi_xspi_calmr_v1_tt<name, baseaddress, offset>;

  template <stdx::ct_string name, std::uint32_t baseaddress>
  using xspix_t =
    groov::group<name,
                 groov::mmio_bus<>,
                 xspi_cr_tt<"xspi_cr", baseaddress, 0x0>,
                 xspi_dcr1_tt<"xspi_dcr1", baseaddress, 0x8>,
                 xspi_dcr2_tt<"xspi_dcr2", baseaddress, 0xc>,
                 xspi_dcr3_tt<"xspi_dcr3", baseaddress, 0x10>,
                 xspi_dcr4_tt<"xspi_dcr4", baseaddress, 0x14>,
                 xspi_sr_tt<"xspi_sr", baseaddress, 0x20>,
                 xspi_fcr_tt<"xspi_fcr", baseaddress, 0x24>,
                 xspi_dlr_tt<"xspi_dlr", baseaddress, 0x40>,
                 xspi_ar_tt<"xspi_ar", baseaddress, 0x48>,
                 xspi_dr_tt<"xspi_dr", baseaddress, 0x50>,
                 xspi_psmkr_tt<"xspi_psmkr", baseaddress, 0x80>,
                 xspi_psmar_tt<"xspi_psmar", baseaddress, 0x88>,
                 xspi_pir_tt<"xspi_pir", baseaddress, 0x90>,
                 xspi_ccr_tt<"xspi_ccr", baseaddress, 0x100>,
                 xspi_tcr_tt<"xspi_tcr", baseaddress, 0x108>,
                 xspi_ir_tt<"xspi_ir", baseaddress, 0x110>,
                 xspi_abr_tt<"xspi_abr", baseaddress, 0x120>,
                 xspi_lptr_tt<"xspi_lptr", baseaddress, 0x130>,
                 xspi_wpccr_tt<"xspi_wpccr", baseaddress, 0x140>,
                 xspi_wptcr_tt<"xspi_wptcr", baseaddress, 0x148>,
                 xspi_wpir_tt<"xspi_wpir", baseaddress, 0x150>,
                 xspi_wpabr_tt<"xspi_wpabr", baseaddress, 0x160>,
                 xspi_wccr_tt<"xspi_wccr", baseaddress, 0x180>,
                 xspi_wtcr_tt<"xspi_wtcr", baseaddress, 0x188>,
                 xspi_wir_tt<"xspi_wir", baseaddress, 0x190>,
                 xspi_wabr_tt<"xspi_wabr", baseaddress, 0x1a0>,
                 xspi_hlcr_tt<"xspi_hlcr", baseaddress, 0x200>,
                 xspi_calfcr_tt<"xspi_calfcr", baseaddress, 0x210>,
                 xspi_calmr_tt<"xspi_calmr", baseaddress, 0x218>,
                 xspi_calsor_tt<"xspi_calsor", baseaddress, 0x220>,
                 xspi_calsir_tt<"xspi_calsir", baseaddress, 0x228>>;

} // namespace xspix
