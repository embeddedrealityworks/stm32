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

    inc = include_directories('include')

    stm32_dep = declare_dependency(
        include_directories: inc,
        dependencies: [groov_dep],
    )

else
    subdir('docs')
    subdir('tools')
endif

