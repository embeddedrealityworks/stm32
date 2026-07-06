
namespace lpuart {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr1_tt = regs::lpuart_cr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr2_tt = regs::lpuart_lpuart_cr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr3_tt = regs::lpuart_lpuart_cr3_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using brr_tt = regs::lpuart_lpuart_brr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using rqr_tt = regs::lpuart_lpuart_rqr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using isr_tt = regs::lpuart_isr_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using icr_tt = regs::lpuart_lpuart_icr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using rdr_tt = regs::usart_usart_rdr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tdr_tt = regs::usart_usart_tdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using presc_tt = regs::usart_usart_presc_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using lpuart_t =
    groov::group<"lpuart",
                 groov::mmio_bus<>,
                 cr1_tt<"cr1", baseaddress, 0x0>,
                 cr2_tt<"cr2", baseaddress, 0x4>,
                 cr3_tt<"cr3", baseaddress, 0x8>,
                 brr_tt<"brr", baseaddress, 0xc>,
                 rqr_tt<"rqr", baseaddress, 0x18>,
                 isr_tt<"isr", baseaddress, 0x1c>,
                 icr_tt<"icr", baseaddress, 0x20>,
                 rdr_tt<"rdr", baseaddress, 0x24>,
                 tdr_tt<"tdr", baseaddress, 0x28>,
                 presc_tt<"presc", baseaddress, 0x2c>>;

} // namespace lpuart
