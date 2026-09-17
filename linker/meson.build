ld_conf = configuration_data()

ld_conf.set('flash_origin', meson.get_external_property('flash_origin'))
ld_conf.set('flash_kb', meson.get_external_property('flash_kb'))
ld_conf.set('ram_origin', meson.get_external_property('ram_origin'))
ld_conf.set('ram_kb', meson.get_external_property('ram_kb'))
ld_conf.set('heap_size', meson.get_external_property('heap_size'))
ld_conf.set('stack_size', meson.get_external_property('stack_size'))

ld_script_in = meson.current_source_dir() / 'stm32.ld.in'

ld_script = configure_file(
  input: ld_script_in,
  output: 'linker.ld',
  configuration: ld_conf,
  )

