
namespace usart1x {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_cr1_tt = regs::usart_usart_cr1_enabled_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_cr1_alternate1_tt = regs::usart_usart_cr1_disabled_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_cr2_tt = regs::usart_usart_cr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_cr3_tt = regs::usart_usart_cr3_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_cr3_alternate1_tt = regs::usart_usart_cr3_alternate1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_brr_tt = regs::usart_usart_brr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_gtpr_tt = regs::usart_usart_gtpr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_rtor_tt = regs::usart_usart_rtor_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_rqr_tt = regs::usart_usart_rqr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_isr_tt = regs::usart_usart_isr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_isr_alternate1_tt = regs::usart_usart_isr_alternate1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_icr_tt = regs::usart_usart_icr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_rdr_tt = regs::usart_usart_rdr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_tdr_tt = regs::usart_usart_tdr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using usart1_presc_tt = regs::usart_usart_presc_v1_tt<name, baseaddress, offset>;

  template <stdx::ct_string name, std::uint32_t baseaddress>
  using usart1x_t =
    groov::group<name,
                 groov::mmio_bus<>,
                 usart1_cr1_tt<"usart1_cr1", baseaddress, 0x0>,
                 usart1_cr1_alternate1_tt<"usart1_cr1_alternate1", baseaddress, 0x0>,
                 usart1_cr2_tt<"usart1_cr2", baseaddress, 0x4>,
                 usart1_cr3_tt<"usart1_cr3", baseaddress, 0x8>,
                 usart1_cr3_alternate1_tt<"usart1_cr3_alternate1", baseaddress, 0x8>,
                 usart1_brr_tt<"usart1_brr", baseaddress, 0xc>,
                 usart1_gtpr_tt<"usart1_gtpr", baseaddress, 0x10>,
                 usart1_rtor_tt<"usart1_rtor", baseaddress, 0x14>,
                 usart1_rqr_tt<"usart1_rqr", baseaddress, 0x18>,
                 usart1_isr_tt<"usart1_isr", baseaddress, 0x1c>,
                 usart1_isr_alternate1_tt<"usart1_isr_alternate1", baseaddress, 0x1c>,
                 usart1_icr_tt<"usart1_icr", baseaddress, 0x20>,
                 usart1_rdr_tt<"usart1_rdr", baseaddress, 0x24>,
                 usart1_tdr_tt<"usart1_tdr", baseaddress, 0x28>,
                 usart1_presc_tt<"usart1_presc", baseaddress, 0x2c>>;

} // namespace usart1x
