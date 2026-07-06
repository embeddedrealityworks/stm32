
namespace opamp {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using opamp1_csr_tt = regs::opamp_opamp1_csr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using opamp2_csr_tt = regs::opamp_opamp1_csr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using opamp3_csr_tt = regs::opamp_opamp1_csr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using opamp4_csr_tt = regs::opamp_opamp1_csr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using opamp5_csr_tt = regs::opamp_opamp1_csr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using opamp6_csr_tt = regs::opamp_opamp1_csr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using opamp1_tcmr_tt = regs::opamp_opamp1_tcmr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using opamp2_tcmr_tt = regs::opamp_opamp1_tcmr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using opamp3_tcmr_tt = regs::opamp_opamp1_tcmr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using opamp4_tcmr_tt = regs::opamp_opamp1_tcmr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using opamp5_tcmr_tt = regs::opamp_opamp1_tcmr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using opamp6_tcmr_tt = regs::opamp_opamp1_tcmr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using opamp_t =
    groov::group<"opamp",
                 groov::mmio_bus<>,
                 opamp1_csr_tt<"opamp1_csr", baseaddress, 0x0>,
                 opamp2_csr_tt<"opamp2_csr", baseaddress, 0x4>,
                 opamp3_csr_tt<"opamp3_csr", baseaddress, 0x8>,
                 opamp4_csr_tt<"opamp4_csr", baseaddress, 0xc>,
                 opamp5_csr_tt<"opamp5_csr", baseaddress, 0x10>,
                 opamp6_csr_tt<"opamp6_csr", baseaddress, 0x14>,
                 opamp1_tcmr_tt<"opamp1_tcmr", baseaddress, 0x18>,
                 opamp2_tcmr_tt<"opamp2_tcmr", baseaddress, 0x1c>,
                 opamp3_tcmr_tt<"opamp3_tcmr", baseaddress, 0x20>,
                 opamp4_tcmr_tt<"opamp4_tcmr", baseaddress, 0x24>,
                 opamp5_tcmr_tt<"opamp5_tcmr", baseaddress, 0x28>,
                 opamp6_tcmr_tt<"opamp6_tcmr", baseaddress, 0x2c>>;

} // namespace opamp
