#include <algorithm>
#include <cstdint>

// Linker-provided symbols

// NOLINTBEGIN:(*-identifier-naming)
extern "C" std::uint32_t _estack;
extern "C" std::uint32_t __data_start_flash;
extern "C" std::uint32_t _sdata;
extern "C" std::uint32_t _edata;
extern "C" std::uint32_t _sbss;
extern "C" std::uint32_t _ebss;

// Forward declaration of functions
extern auto main() -> int;

extern "C" void _reset();
extern "C" void _default();

extern void (*__init_array_start[])();
extern void (*__init_array_end[])();

// Weak aliases for core exception handlers
extern "C" void _nmi() __attribute__((weak, alias("_default")));
extern "C" void _hardfault() __attribute__((weak, alias("_default")));
extern "C" void _memmanage() __attribute__((weak, alias("_default")));
extern "C" void _busfault() __attribute__((weak, alias("_default")));
extern "C" void _usagefault() __attribute__((weak, alias("_default")));
extern "C" void _securefault() __attribute__((weak, alias("_default")));
extern "C" void _svcall() __attribute__((weak, alias("_default")));
extern "C" void _debugmon() __attribute__((weak, alias("_default")));
extern "C" void _pendsv() __attribute__((weak, alias("_default")));
extern "C" void _systick() __attribute__((weak, alias("_default")));

// Weak aliases for peripheral interrupt handlers


extern "C" const volatile std::uintptr_t vector_table[]
  __attribute__((section(".isr_vector"))) = {
    reinterpret_cast<std::uintptr_t>(&_estack),    // 0: Initial stack pointer
    reinterpret_cast<std::uintptr_t>(&_reset),     // 1: Reset handler
    reinterpret_cast<std::uintptr_t>(&_nmi),       // 2: NMI handler
    reinterpret_cast<std::uintptr_t>(&_hardfault), // 3: Hard fault handler
    reinterpret_cast<std::uintptr_t>(
      &_memmanage), // 4: Memory management fault handler
    reinterpret_cast<std::uintptr_t>(&_busfault),   // 5: Bus fault handler
    reinterpret_cast<std::uintptr_t>(&_usagefault), // 6: Usage fault handler
    0,                                              // 7: Reserved / SecureFault
    0,                                              // 8: Reserved
    0,                                              // 9: Reserved
    0,                                              // 10: Reserved
    reinterpret_cast<std::uintptr_t>(&_svcall),     // 11: SVCall handler
    reinterpret_cast<std::uintptr_t>(&_debugmon),   // 12: Debug monitor handler
    0,                                              // 13: Reserved
    reinterpret_cast<std::uintptr_t>(&_pendsv),     // 14: PendSV handler
    reinterpret_cast<std::uintptr_t>(
      &_systick) // 15: SysTick handler (entry point)
};

extern "C" void _reset() {
  std::copy(&__data_start_flash, &__data_start_flash + (&_edata - &_sdata),
            &_sdata);
  std::fill(&_sbss, &_ebss, 0u);
  std::for_each(__init_array_start, __init_array_end,
                [](auto init_func) { init_func(); });
  main();
  while (true) {}
}

extern "C" void _default() {
  while (true) {}
}

// NOLINTEND:(*-identifier-naming)
