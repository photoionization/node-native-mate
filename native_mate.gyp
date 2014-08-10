{
  'targets': [
    {
      'includes': [ 'vendor/src/native_mate_files.gypi' ],
      'target_name': 'native_mate',
      'type': 'static_library',
      'direct_dependent_settings': {
        'include_dirs': [
          'vendor/src',
          'header_redirect',
        ],
      },
      'export_dependent_settings': [ 'vendor/base-minimal/base.gyp:base', ],
      'dependencies': [ 'vendor/base-minimal/base.gyp:base', ],
      'include_dirs': [
        'vendor/src',
        'header_redirect',
      ],
      'sources': [
        'header_redirect/uv/include/uv.h',
        'header_redirect/v8/include/v8.h',
        '<@(native_mate_files)',
      ],
    },
    {
      'target_name': 'native_mate_test',
      'type': 'static_library',
      'dependencies': [
        'native_mate',
      ],
      'sources': [
        'tests/compilation.cc'
      ],
    },
  ],
}
