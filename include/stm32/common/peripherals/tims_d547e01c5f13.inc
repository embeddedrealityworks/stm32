
namespace tim16 {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr1_tt = regs::tim_cr1_v6_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr2_tt = regs::tim_cr2_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dier_tt = regs::tim_dier_v9_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using sr_tt = regs::tim_sr_v8_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using egr_tt = regs::tim_egr_v8_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccmr1_output_tt = regs::tims_ccmr1_output_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccmr1_input_tt = regs::tim_ccmr1_input_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccer_tt = regs::tim_ccer_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cnt_tt = regs::tim_tim1_cnt_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using psc_tt = regs::tim_psc_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using arr_tt = regs::tim_arr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using rcr_tt = regs::tim_rcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccr1_tt = regs::tim_ccr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using bdtr_tt = regs::tims_bdtr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dcr_tt = regs::tim_dcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dmar_tt = regs::tim_dmar_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim16_af1_tt = regs::tim_af1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim16_tisel_tt = regs::tim_tisel_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using tim16_t =
    groov::group<"tim16",
                 groov::mmio_bus<>,
                 cr1_tt<"cr1", baseaddress, 0x0>,
                 cr2_tt<"cr2", baseaddress, 0x4>,
                 dier_tt<"dier", baseaddress, 0xc>,
                 sr_tt<"sr", baseaddress, 0x10>,
                 egr_tt<"egr", baseaddress, 0x14>,
                 ccmr1_output_tt<"ccmr1_output", baseaddress, 0x18>,
                 ccmr1_input_tt<"ccmr1_input", baseaddress, 0x18>,
                 ccer_tt<"ccer", baseaddress, 0x20>,
                 cnt_tt<"cnt", baseaddress, 0x24>,
                 psc_tt<"psc", baseaddress, 0x28>,
                 arr_tt<"arr", baseaddress, 0x2c>,
                 rcr_tt<"rcr", baseaddress, 0x30>,
                 ccr1_tt<"ccr1", baseaddress, 0x34>,
                 bdtr_tt<"bdtr", baseaddress, 0x44>,
                 dcr_tt<"dcr", baseaddress, 0x48>,
                 dmar_tt<"dmar", baseaddress, 0x4c>,
                 tim16_af1_tt<"tim16_af1", baseaddress, 0x60>,
                 tim16_tisel_tt<"tim16_tisel", baseaddress, 0x68>>;

} // namespace tim16

namespace tim17 {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr1_tt = regs::tim_cr1_v6_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr2_tt = regs::tim_cr2_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dier_tt = regs::tim_dier_v9_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using sr_tt = regs::tim_sr_v8_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using egr_tt = regs::tim_egr_v8_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccmr1_output_tt = regs::tims_ccmr1_output_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccmr1_input_tt = regs::tim_ccmr1_input_v3_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccer_tt = regs::tim_ccer_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cnt_tt = regs::tim_tim1_cnt_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using psc_tt = regs::tim_psc_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using arr_tt = regs::tim_arr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using rcr_tt = regs::tim_rcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccr1_tt = regs::tim_ccr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using bdtr_tt = regs::tims_bdtr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dcr_tt = regs::tim_dcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dmar_tt = regs::tim_dmar_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim17_af1_tt = regs::tim_af1_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tim17_tisel_tt = regs::tim_tisel_v1_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using tim17_t =
    groov::group<"tim17",
                 groov::mmio_bus<>,
                 cr1_tt<"cr1", baseaddress, 0x0>,
                 cr2_tt<"cr2", baseaddress, 0x4>,
                 dier_tt<"dier", baseaddress, 0xc>,
                 sr_tt<"sr", baseaddress, 0x10>,
                 egr_tt<"egr", baseaddress, 0x14>,
                 ccmr1_output_tt<"ccmr1_output", baseaddress, 0x18>,
                 ccmr1_input_tt<"ccmr1_input", baseaddress, 0x18>,
                 ccer_tt<"ccer", baseaddress, 0x20>,
                 cnt_tt<"cnt", baseaddress, 0x24>,
                 psc_tt<"psc", baseaddress, 0x28>,
                 arr_tt<"arr", baseaddress, 0x2c>,
                 rcr_tt<"rcr", baseaddress, 0x30>,
                 ccr1_tt<"ccr1", baseaddress, 0x34>,
                 bdtr_tt<"bdtr", baseaddress, 0x44>,
                 dcr_tt<"dcr", baseaddress, 0x48>,
                 dmar_tt<"dmar", baseaddress, 0x4c>,
                 tim17_af1_tt<"tim17_af1", baseaddress, 0x60>,
                 tim17_tisel_tt<"tim17_tisel", baseaddress, 0x68>>;

} // namespace tim17

namespace tim15 {
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr1_tt = regs::tim_cr1_v6_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cr2_tt = regs::tim_cr2_v6_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using smcr_tt = regs::tims_smcr_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dier_tt = regs::tims_dier_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using sr_tt = regs::tim_sr_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using egr_tt = regs::tim_egr_v5_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccmr1_output_tt = regs::tims_ccmr1_output_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccmr1_input_tt = regs::tim_ccmr1_input_v2_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccer_tt = regs::tim_ccer_v4_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using cnt_tt = regs::tim_tim1_cnt_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using psc_tt = regs::tim_psc_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using arr_tt = regs::tim_arr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using rcr_tt = regs::tim_rcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccr1_tt = regs::tim_ccr1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using ccr2_tt = regs::tim_ccr2_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using bdtr_tt = regs::tims_bdtr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dcr_tt = regs::tim_dcr_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using dmar_tt = regs::tim_dmar_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using af1_tt = regs::tims_af1_v1_tt<name, baseaddress, offset>;
  template <stdx::ct_string name,
            std::uint32_t   baseaddress,
            std::uint32_t   offset>
  using tisel_tt = regs::tim_tisel_v4_tt<name, baseaddress, offset>;

  template <std::uint32_t baseaddress>
  using tim15_t =
    groov::group<"tim15",
                 groov::mmio_bus<>,
                 cr1_tt<"cr1", baseaddress, 0x0>,
                 cr2_tt<"cr2", baseaddress, 0x4>,
                 smcr_tt<"smcr", baseaddress, 0x8>,
                 dier_tt<"dier", baseaddress, 0xc>,
                 sr_tt<"sr", baseaddress, 0x10>,
                 egr_tt<"egr", baseaddress, 0x14>,
                 ccmr1_output_tt<"ccmr1_output", baseaddress, 0x18>,
                 ccmr1_input_tt<"ccmr1_input", baseaddress, 0x18>,
                 ccer_tt<"ccer", baseaddress, 0x20>,
                 cnt_tt<"cnt", baseaddress, 0x24>,
                 psc_tt<"psc", baseaddress, 0x28>,
                 arr_tt<"arr", baseaddress, 0x2c>,
                 rcr_tt<"rcr", baseaddress, 0x30>,
                 ccr1_tt<"ccr1", baseaddress, 0x34>,
                 ccr2_tt<"ccr2", baseaddress, 0x38>,
                 bdtr_tt<"bdtr", baseaddress, 0x44>,
                 dcr_tt<"dcr", baseaddress, 0x48>,
                 dmar_tt<"dmar", baseaddress, 0x4c>,
                 af1_tt<"af1", baseaddress, 0x60>,
                 tisel_tt<"tisel", baseaddress, 0x68>>;

} // namespace tim15
