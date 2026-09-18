project(
    'stm32',
    'cpp',
    version: '0.1.1',
    default_options: [
        'cpp_std=c++23',
    ],
    meson_version: '>=1.10',
)

if meson.is_subproject()

    groov_sub = subproject('generic-register-operation-optimizer')
    groov_dep = groov_sub.get_variable('groov_dep')

    stm32_mcu = meson.get_external_property('stm32_mcu')

    subdir('include/stm32')
    subdir('linker')
    subdir('src')

    inc = include_directories('include')

    stm32_lib = static_library(
      'stm32_lib',
      startup_src,
      )

    stm32_dep = declare_dependency(
        include_directories: inc,
        dependencies: [groov_dep],
        link_with: stm32_lib,
        link_args: ['-T', ld_script.full_path()],
    )

else
    subdir('tools')
    subdir('docs')
endif
