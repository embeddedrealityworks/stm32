
namespace tim16x {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_cr1_tt = regs::tim_tim16_cr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_cr2_tt = regs::tim_tim16_cr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_dier_tt = regs::tim_tim16_dier_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_sr_tt = regs::tim_tim16_sr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_egr_tt = regs::tim16_tim16_egr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_ccmr1_tt = regs::tim_tim14_ccmr1_input_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_ccmr1_alternate1_tt = regs::tim_tim16_ccmr1_alternate_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_ccer_tt = regs::tim_tim16_ccer_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_cnt_tt = regs::tim_tim1_cnt_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_psc_tt = regs::tim_tim1_psc_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_arr_tt = regs::tim_tim1_arr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_rcr_tt = regs::tim_tim16_rcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_ccr1_tt = regs::tim_tim1_ccr1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_bdtr_tt = regs::tim_tim16_bdtr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_dtr2_tt = regs::tim_tim1_dtr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_tisel_tt = regs::tim_tim14_tisel_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_af1_tt = regs::tim_tim16_af1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_af2_tt = regs::tim_tim2_af2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_or1_tt = regs::tim16_tim16_or1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_dcr_tt = regs::tim_tim1_dcr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim_dmar_tt = regs::tim_tim1_dmar_v1_tt<name, baseaddress, offset>;

  template <stdx::ct_string name, std::uint32_t baseaddress>
  using tim16x_t =
    groov::group<name,
                 groov::mmio_bus<>,
                 tim_cr1_tt<"tim_cr1", baseaddress, 0x0>,
                 tim_cr2_tt<"tim_cr2", baseaddress, 0x4>,
                 tim_dier_tt<"tim_dier", baseaddress, 0xc>,
                 tim_sr_tt<"tim_sr", baseaddress, 0x10>,
                 tim_egr_tt<"tim_egr", baseaddress, 0x14>,
                 tim_ccmr1_tt<"tim_ccmr1", baseaddress, 0x18>,
                 tim_ccmr1_alternate1_tt<"tim_ccmr1_alternate1", baseaddress, 0x18>,
                 tim_ccer_tt<"tim_ccer", baseaddress, 0x20>,
                 tim_cnt_tt<"tim_cnt", baseaddress, 0x24>,
                 tim_psc_tt<"tim_psc", baseaddress, 0x28>,
                 tim_arr_tt<"tim_arr", baseaddress, 0x2c>,
                 tim_rcr_tt<"tim_rcr", baseaddress, 0x30>,
                 tim_ccr1_tt<"tim_ccr1", baseaddress, 0x34>,
                 tim_bdtr_tt<"tim_bdtr", baseaddress, 0x44>,
                 tim_dtr2_tt<"tim_dtr2", baseaddress, 0x54>,
                 tim_tisel_tt<"tim_tisel", baseaddress, 0x5c>,
                 tim_af1_tt<"tim_af1", baseaddress, 0x60>,
                 tim_af2_tt<"tim_af2", baseaddress, 0x64>,
                 tim_or1_tt<"tim_or1", baseaddress, 0x68>,
                 tim_dcr_tt<"tim_dcr", baseaddress, 0x3dc>,
                 tim_dmar_tt<"tim_dmar", baseaddress, 0x3e0>>;

} // namespace tim16x
