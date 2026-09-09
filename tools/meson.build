cli23_sub = subproject('cli23')
cli23_dep = cli23_sub.get_variable('cli23_dep')

boost_dep = dependency('boost', required: true)

svd2groov_src = files('svd2groov.cpp')

# A build-time codegen tool: always optimized, threaded over the SVD list.
# Unoptimized it is ~10x slower and thread scaling collapses.
svd2groov = executable(
  'svd2groov',
  svd2groov_src,
  dependencies: [cli23_dep, boost_dep],
  native: true,
  override_options: ['optimization=2', 'b_ndebug=true'],
  )
