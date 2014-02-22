{
  'targets': [
    {
      'target_name': 'native_mate',
      'type': 'static_library',
      'direct_dependent_settings': {
        'include_dirs': [
          '.',
          'vendor',
        ],
      },
      'export_dependent_settings': [ 'vendor/base-minimal/base.gyp:base', ],
      'dependencies': [ 'vendor/base-minimal/base.gyp:base', ],
      'include_dirs': [
        '.',
      ],
      'sources': [
        'native_mate/empty.cc',
        'gin/arguments.cc',
        'gin/arguments.h',
        'gin/converter.cc',
        'gin/converter.h',
        'vendor/nan/nan.h',
      ],
    },
  ],
}

