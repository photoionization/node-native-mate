# native-mate

A non-intrusive lightweight JS to C++ bindings for node, forked from Chromium's
[gin](https://code.google.com/p/chromium/codesearch#chromium/src/gin/README)
library. It also provides access to Chromium's `base` library via including the
[base-minimal](https://github.com/zcbenz/base-minimal) library.

## Usage

1. Add `native-mate` to `package.json`'s dependencies.
2. Add `"dependencies": [ "<!(node -e \"require('native-mate')\")" ],` to
   `binding.gyp`.

## Docs

API references of native-mate can be found in the
[docs](https://github.com/zcbenz/node-native-mate/tree/master/docs) directory.
