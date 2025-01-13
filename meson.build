
project('battle_c_bot', 'c',
  version: '0.1.0',
)

# BattleC Library
battle_c_include = include_directories('lib/battle_c/include')
battle_c_lib_path = 'lib/battle_c'

# Dependency configuration
battle_c_dep = declare_dependency(
    include_directories: battle_c_include,
    link_args: ['-L' + meson.project_source_root() + '/' + battle_c_lib_path, '-lbattle_c']
)

# Define executable source files
executable_sources = files('src/main.c')

# Create the executable
executable(
    'second_project_exe',
    executable_sources,
    dependencies: [battle_c_dep],
    install: true,
    build_rpath: meson.project_source_root() + '/' + battle_c_lib_path, # Use absolute path for build phase
    install_rpath: '$ORIGIN/../lib/battle_c' # Use relative path for installed executable
)


