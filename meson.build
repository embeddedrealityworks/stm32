project(
    'stm32',
    'cpp',
    version: '0.1.1',
    default_options: [
        'cpp_std=c++23',
    ],
    meson_version: '>=1.10',
)

fs = import('fs')

if meson.is_subproject()

    groov_sub = subproject('generic-register-operation-optimizer')
    groov_dep = groov_sub.get_variable('groov_dep')

    ioc_file = get_option('ioc')
    if not fs.exists(ioc_file)
        error('The specified ioc file does not exist: ' + ioc_file)
    endif

    # configure headers
    subdir('include/stm32')
    # configure linker script
    subdir('linker')
    # fetch source files
    subdir('src')

    inc = include_directories('include')

    stm32_lib = static_library(
      'stm32_lib',
      stm32_src,
      )

    stm32_dep = declare_dependency(
        include_directories: inc,
        dependencies: [groov_dep],
        link_with: stm32_lib,
        link_args: ['-T', ld_script.full_path()],
    )

else
    subdir('docs')
endif
