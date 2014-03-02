# native-mate

A non-intrusive lightweight bindings for V8 and libuv, forked from Chromium's
[gin](https://code.google.com/p/chromium/codesearch#chromium/src/gin/README)
library.

It also provides access to Chromium's `base` library via including the
[base-minimal](https://github.com/zcbenz/base-minimal) library.

## Usage

1. Add `native-mate` to your `package.json`'s dependencies.
2. Edit your `binding.gyp`:
  ```gyp
  "dependencies": [ "<!(node -e \"require('native-mate')\")" ],
  ```
