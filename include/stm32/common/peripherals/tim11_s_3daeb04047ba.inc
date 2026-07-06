
namespace tim11_s {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim11_cr1_tt = regs::tim_tim16_cr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim11_dier_tt = regs::tim_tim14_dier_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim11_sr_tt = regs::tim_tim14_sr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim11_egr_tt = regs::tim_tim14_egr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim11_ccmr1_input_tt = regs::tim_tim14_ccmr1_input_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim11_ccmr1_output_tt = regs::tim14_tim14_ccmr1_alternate1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim11_ccer_tt = regs::tim_tim14_ccer_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim11_cnt_tt = regs::tim_tim3_cnt_alternate_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim11_psc_tt = regs::tim_tim1_psc_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim11_arr_tt = regs::tim_tim1_arr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim11_ccr1_tt = regs::tim_tim1_ccr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim11_tisel_tt = regs::tim_tim14_tisel_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using tim11_s_t =
    groov::group<"tim11_s",
                 groov::mmio_bus<>,
                 tim11_cr1_tt<"tim11_cr1", baseaddress, 0x0>,
                 tim11_dier_tt<"tim11_dier", baseaddress, 0xc>,
                 tim11_sr_tt<"tim11_sr", baseaddress, 0x10>,
                 tim11_egr_tt<"tim11_egr", baseaddress, 0x14>,
                 tim11_ccmr1_input_tt<"tim11_ccmr1_input", baseaddress, 0x18>,
                 tim11_ccmr1_output_tt<"tim11_ccmr1_output", baseaddress, 0x18>,
                 tim11_ccer_tt<"tim11_ccer", baseaddress, 0x20>,
                 tim11_cnt_tt<"tim11_cnt", baseaddress, 0x24>,
                 tim11_psc_tt<"tim11_psc", baseaddress, 0x28>,
                 tim11_arr_tt<"tim11_arr", baseaddress, 0x2c>,
                 tim11_ccr1_tt<"tim11_ccr1", baseaddress, 0x34>,
                 tim11_tisel_tt<"tim11_tisel", baseaddress, 0x5c>>;

} // namespace tim11_s
