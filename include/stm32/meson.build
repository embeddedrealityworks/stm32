family = meson.get_external_property('mcu_family')

conf = configuration_data()
conf.set('MCU', stm32_mcu)
conf.set('FAMILY', family)
configure_file(
    input: 'mcu.hpp.in',
    output: 'mcu.hpp',
    configuration: conf,
)
