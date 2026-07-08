fs = import('fs')

family = ''
foreach line : fs.read('mcu_family.txt').strip().split('\n')
    kv = line.split('=')
    if kv[0] == stm32_mcu
        family = kv[1]
    endif
endforeach
if family == ''
    error('stm32_mcu \'@0@\' not found in mcu_family.txt'.format(stm32_mcu))
endif

conf = configuration_data()
conf.set('MCU', stm32_mcu)
conf.set('FAMILY', family)
configure_file(
    input: 'mcu.hpp.in',
    output: 'mcu.hpp',
    configuration: conf,
)
