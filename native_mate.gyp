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
        'vendor/src',
        'header_redirect',
      ],
      'sources': [
        'header_redirect/uv/include/uv.h',
        'header_redirect/v8/include/v8.h',
        'vendor/src/native_mate/arguments.cc',
        'vendor/src/native_mate/arguments.h',
        'vendor/src/native_mate/compat.h',
        'vendor/src/native_mate/converter.cc',
        'vendor/src/native_mate/converter.h',
        'vendor/src/native_mate/dictionary.cc',
        'vendor/src/native_mate/dictionary.h',
        'vendor/src/native_mate/function_template.cc',
        'vendor/src/native_mate/function_template.h',
        'vendor/src/native_mate/handle.h',
        'vendor/src/native_mate/object_template_builder.cc',
        'vendor/src/native_mate/object_template_builder.h',
        'vendor/src/native_mate/scoped_persistent.h',
        'vendor/src/native_mate/try_catch.cc',
        'vendor/src/native_mate/try_catch.h',
        'vendor/src/native_mate/wrappable.cc',
        'vendor/src/native_mate/wrappable.h',
      ],
    },
  ],
}
