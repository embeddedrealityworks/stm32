
namespace i2c2 {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using i2c2_cr1_tt = regs::i2c2_i2c2_cr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using i2c2_cr2_tt = regs::i2c_i2c_cr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using i2c2_oar1_tt = regs::i2c_i2c_oar1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using i2c2_oar2_tt = regs::i2c_i2c_oar2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using i2c2_timing_tt = regs::i2c_i2c_timingr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using i2c2_timeout_tt = regs::i2c2_i2c2_timeout_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using i2c2_isr_tt = regs::i2c_i2c_isr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using i2c2_icr_tt = regs::i2c_i2c_icr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using i2c2_pecr_tt = regs::i2c_i2c_pecr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using i2c2_rxdr_tt = regs::i2c_i2c_rxdr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using i2c2_txdr_tt = regs::i2c_i2c_txdr_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using i2c2_t =
    groov::group<"i2c2",
                 groov::mmio_bus<>,
                 i2c2_cr1_tt<"i2c2_cr1", baseaddress, 0x0>,
                 i2c2_cr2_tt<"i2c2_cr2", baseaddress, 0x4>,
                 i2c2_oar1_tt<"i2c2_oar1", baseaddress, 0x8>,
                 i2c2_oar2_tt<"i2c2_oar2", baseaddress, 0xc>,
                 i2c2_timing_tt<"i2c2_timing", baseaddress, 0x10>,
                 i2c2_timeout_tt<"i2c2_timeout", baseaddress, 0x14>,
                 i2c2_isr_tt<"i2c2_isr", baseaddress, 0x18>,
                 i2c2_icr_tt<"i2c2_icr", baseaddress, 0x1c>,
                 i2c2_pecr_tt<"i2c2_pecr", baseaddress, 0x20>,
                 i2c2_rxdr_tt<"i2c2_rxdr", baseaddress, 0x24>,
                 i2c2_txdr_tt<"i2c2_txdr", baseaddress, 0x28>>;

} // namespace i2c2
