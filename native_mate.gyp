{
  'targets': [
    {
      'target_name': 'native_mate',
      'type': 'static_library',
      'direct_dependent_settings': {
        'include_dirs': [
          '.',
          'header_redirect',
        ],
      },
      'export_dependent_settings': [ 'vendor/base-minimal/base.gyp:base', ],
      'dependencies': [ 'vendor/base-minimal/base.gyp:base', ],
      'include_dirs': [
        '.',
        'header_redirect',
      ],
      'sources': [
        'header_redirect/uv/include/uv.h',
        'header_redirect/v8/include/v8.h',
        'native_mate/arguments.cc',
        'native_mate/arguments.h',
        'native_mate/converter.cc',
        'native_mate/converter.h',
        'native_mate/dictionary.cc',
        'native_mate/dictionary.h',
        'native_mate/function_template.cc',
        'native_mate/function_template.h',
        'native_mate/handle.h',
        'native_mate/object_template_builder.cc',
        'native_mate/object_template_builder.h',
        'native_mate/try_catch.cc',
        'native_mate/try_catch.h',
        'native_mate/wrappable.cc',
        'native_mate/wrappable.h',
        'vendor/nan/nan.h',
      ],
    },
  ],
}
