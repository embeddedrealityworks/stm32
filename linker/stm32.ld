ENTRY(_reset)

MEMORY
{
  BOOT (rx!w) : ORIGIN @boot_flash@, LENGTH = @flash_kb@K
  FLASH (rx) : ORIGIN = @flash_origin@, LENGTH = @flash_kb@K
  RAM (xrw) : ORIGIN = @ram_origin@, LENGTH = @ram_kb@K
}

_Min_Heap_Size = @heap_size@;
_Min_Stack_Size = @stack_size@;

SECTIONS
{
  /* interrupt vector tables */
  /* .isr_vector - ARM core exceptions */
  .isr_vector :
  {
    . = ALIGN(4);
    _sisr_vector = .;
    KEEP(*(.isr_vector))
    KEEP(*(.isr_vector.device))
    . = ALIGN(4);
    _eisr_vector = .;
} >FLASH

.text :
{
  . = ALIGN(4);
  _stext = .;
  *(.text)
  *(.text*)
  *(.glue_7)
  *(.glue_7t)
  *(.eh_frame)
  KEEP(*(.init))
  KEEP(*(.fini))
  . = ALIGN(4);
  _etext = .;
} >FLASH

.init_array :
{
  . = ALIGN(4);
  PROVIDE_HIDDEN (__init_array_start = .);
  KEEP(*(SORT(.init_array.*)))
  KEEP(*(.init_array*))
  PROVIDE_HIDDEN (__init_array_end = .);
} >FLASH

.fini_array :
{
  . = ALIGN(4);
  PROVIDE_HIDDEN (__fini_array_start = .);
  KEEP(*(SORT(.fini_array.*)))
  KEEP(*(.fini_array*))
  PROVIDE_HIDDEN (__fini_array_end = .);
} >FLASH

.rodata :
{
  . = ALIGN(4);
  _srodata = .;
  *(.rodata)
  *(.rodata*)
  . = ALIGN(4);
  _erodata = .;
} >FLASH

.data :
{
  . = ALIGN(4);
  _sdata = .;
  *(.data)
  *(.data*)
  . = ALIGN(4);
  _edata = .;
} >RAM AT>FLASH

__data_start_flash = LOADADDR(.data);
__data_start_ram = ADDR(.data);
__data_size = SIZEOF(.data)

.bss :
{
  . = ALIGN(4);
  _sbss = .;
  *(.bss)
  *(.bss*)
  *(COMMON)
  . = ALIGN(4);
  _ebss = .;
} >RAM

}
