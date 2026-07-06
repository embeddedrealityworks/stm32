
namespace rcc {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr_tt = regs::rcc_cr_v11_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using icscr_tt = regs::rcc_icscr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cfgr_tt = regs::rcc_cfgr_v21_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cir_tt = regs::rcc_cir_v7_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ahbrstr_tt = regs::rcc_ahbrstr_v14_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using apb2rstr_tt = regs::rcc_apb2rstr_v24_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using apb1rstr_tt = regs::rcc_apb1rstr_v25_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ahbenr_tt = regs::rcc_ahbenr_v18_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using apb2enr_tt = regs::rcc_apb2enr_v25_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using apb1enr_tt = regs::rcc_apb1enr_v25_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ahblpenr_tt = regs::rcc_ahblpenr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using apb2lpenr_tt = regs::rcc_apb2lpenr_v14_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using apb1lpenr_tt = regs::rcc_apb1lpenr_v10_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using csr_tt = regs::rcc_csr_v10_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using rcc_t =
    groov::group<"rcc",
                 groov::mmio_bus<>,
                 cr_tt<"cr", baseaddress, 0x0>,
                 icscr_tt<"icscr", baseaddress, 0x4>,
                 cfgr_tt<"cfgr", baseaddress, 0x8>,
                 cir_tt<"cir", baseaddress, 0xc>,
                 ahbrstr_tt<"ahbrstr", baseaddress, 0x10>,
                 apb2rstr_tt<"apb2rstr", baseaddress, 0x14>,
                 apb1rstr_tt<"apb1rstr", baseaddress, 0x18>,
                 ahbenr_tt<"ahbenr", baseaddress, 0x1c>,
                 apb2enr_tt<"apb2enr", baseaddress, 0x20>,
                 apb1enr_tt<"apb1enr", baseaddress, 0x24>,
                 ahblpenr_tt<"ahblpenr", baseaddress, 0x28>,
                 apb2lpenr_tt<"apb2lpenr", baseaddress, 0x2c>,
                 apb1lpenr_tt<"apb1lpenr", baseaddress, 0x30>,
                 csr_tt<"csr", baseaddress, 0x34>>;

} // namespace rcc
