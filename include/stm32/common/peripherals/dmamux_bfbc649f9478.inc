
namespace dmamux {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c0cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c1cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c2cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c3cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c4cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c5cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c6cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c7cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c8cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c9cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c10cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c11cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c12cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c13cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c14cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using c15cr_tt = regs::dmamux_c0cr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using rg0cr_tt = regs::dmamux_rg0cr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using rg1cr_tt = regs::dmamux_rg0cr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using rg2cr_tt = regs::dmamux_rg0cr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using rg3cr_tt = regs::dmamux_rg0cr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using rgsr_tt = regs::dmamux_rgsr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using rgcfr_tt = regs::dmamux_rgcfr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using csr_tt = regs::dmamux_csr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cfr_tt = regs::dmamux_cfr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using dmamux_t =
    groov::group<"dmamux",
                 groov::mmio_bus<>,
                 c0cr_tt<"c0cr", baseaddress, 0x0>,
                 c1cr_tt<"c1cr", baseaddress, 0x4>,
                 c2cr_tt<"c2cr", baseaddress, 0x8>,
                 c3cr_tt<"c3cr", baseaddress, 0xc>,
                 c4cr_tt<"c4cr", baseaddress, 0x10>,
                 c5cr_tt<"c5cr", baseaddress, 0x14>,
                 c6cr_tt<"c6cr", baseaddress, 0x18>,
                 c7cr_tt<"c7cr", baseaddress, 0x1c>,
                 c8cr_tt<"c8cr", baseaddress, 0x20>,
                 c9cr_tt<"c9cr", baseaddress, 0x24>,
                 c10cr_tt<"c10cr", baseaddress, 0x28>,
                 c11cr_tt<"c11cr", baseaddress, 0x2c>,
                 c12cr_tt<"c12cr", baseaddress, 0x30>,
                 c13cr_tt<"c13cr", baseaddress, 0x34>,
                 c14cr_tt<"c14cr", baseaddress, 0x38>,
                 c15cr_tt<"c15cr", baseaddress, 0x3c>,
                 rg0cr_tt<"rg0cr", baseaddress, 0x100>,
                 rg1cr_tt<"rg1cr", baseaddress, 0x104>,
                 rg2cr_tt<"rg2cr", baseaddress, 0x108>,
                 rg3cr_tt<"rg3cr", baseaddress, 0x10c>,
                 rgsr_tt<"rgsr", baseaddress, 0x140>,
                 rgcfr_tt<"rgcfr", baseaddress, 0x144>,
                 csr_tt<"csr", baseaddress, 0x80>,
                 cfr_tt<"cfr", baseaddress, 0x84>>;

} // namespace dmamux
