
namespace syscfg_vrefbuf {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_memrmp_tt = regs::syscfg_memrmp_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_cfgr1_tt = regs::syscfg_cfgr1_v9_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_exticr1_tt = regs::syscfg_exticr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_exticr2_tt = regs::syscfg_exticr2_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_exticr3_tt = regs::syscfg_exticr3_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_exticr4_tt = regs::syscfg_exticr4_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_scsr_tt = regs::syscfg_scsr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_cfgr2_tt = regs::syscfg_cfgr2_v6_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_swpr_tt = regs::syscfg_swpr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_skr_tt = regs::rtc_wpr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_swpr2_tt = regs::syscfg_swpr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using vrefbuf_csr_tt = regs::vrefbuf_vrefbuf_csr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using vrefbuf_ccr_tt = regs::vrefbuf_ccr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_imr1_tt = regs::syscfg_imr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_imr2_tt = regs::syscfg_imr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_c2imr1_tt = regs::syscfg_c2imr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_c2imr2_tt = regs::syscfg_c2imr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using syscfg_sipcr_tt = regs::syscfg_sipcr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using syscfg_vrefbuf_t =
    groov::group<"syscfg_vrefbuf",
                 groov::mmio_bus<>,
                 syscfg_memrmp_tt<"syscfg_memrmp", baseaddress, 0x0>,
                 syscfg_cfgr1_tt<"syscfg_cfgr1", baseaddress, 0x4>,
                 syscfg_exticr1_tt<"syscfg_exticr1", baseaddress, 0x8>,
                 syscfg_exticr2_tt<"syscfg_exticr2", baseaddress, 0xc>,
                 syscfg_exticr3_tt<"syscfg_exticr3", baseaddress, 0x10>,
                 syscfg_exticr4_tt<"syscfg_exticr4", baseaddress, 0x14>,
                 syscfg_scsr_tt<"syscfg_scsr", baseaddress, 0x18>,
                 syscfg_cfgr2_tt<"syscfg_cfgr2", baseaddress, 0x1c>,
                 syscfg_swpr_tt<"syscfg_swpr", baseaddress, 0x20>,
                 syscfg_skr_tt<"syscfg_skr", baseaddress, 0x24>,
                 syscfg_swpr2_tt<"syscfg_swpr2", baseaddress, 0x28>,
                 vrefbuf_csr_tt<"vrefbuf_csr", baseaddress, 0x30>,
                 vrefbuf_ccr_tt<"vrefbuf_ccr", baseaddress, 0x34>,
                 syscfg_imr1_tt<"syscfg_imr1", baseaddress, 0x100>,
                 syscfg_imr2_tt<"syscfg_imr2", baseaddress, 0x104>,
                 syscfg_c2imr1_tt<"syscfg_c2imr1", baseaddress, 0x108>,
                 syscfg_c2imr2_tt<"syscfg_c2imr2", baseaddress, 0x10c>,
                 syscfg_sipcr_tt<"syscfg_sipcr", baseaddress, 0x110>>;

} // namespace syscfg_vrefbuf
