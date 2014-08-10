# Converter

The `converter.h` provides a set of helper functions to convert between basic
C++ types and JavaScript types.

## References

### Generic type conversions

Signature:

```c++
template<typename T>
struct Converter<T> {
  static v8::Handle<v8::Value> ToV8(v8::Isolate* isolate, T val);
  static bool FromV8(v8::Isolate* isolate, v8::Handle<v8::Value> val, T* out);
};
```

Example:

```c++
#include "native_mate/converter.h"

v8::Handle<v8::Value> CalledInJavaScript(v8::Isolate* isolate, v8::Handle<v8::Value> value) {
  int number;
  mate::Converter<int>::FromV8(isolate, value, &number);

  std::string str("千江有水千江月，万里无云万里天");
  return mate::Converter<std::string>::ToV8(isolate, str);
}
```

### Helper functions

There are also some helper functions to deduce the type automatically for type
conversions.

Signature:

```c++
template<typename T>
v8::Handle<v8::Value> ConvertToV8(v8::Isolate* isolate, T input);

template<typename T>
bool ConvertFromV8(v8::Isolate* isolate, v8::Handle<v8::Value> input, T* result);

v8::Handle<v8::String> StringToV8(v8::Isolate* isolate, const base::StringPiece& input);
v8::Handle<v8::String> StringToSymbol(v8::Isolate* isolate, const base::StringPiece& input);
```

Example:

```c++
#include "native_mate/converter.h"

v8::Handle<v8::Value> CalledInJavaScript(v8::Isolate* isolate, v8::Handle<v8::Value> value) {
  int number;
  mate::ConvertFromV8(isolate, value, &number);

  std::string str("千江有水千江月，万里无云万里天");
  return StringToV8(isolate, str);
}
```

### Define converter for your own types

By specializing the `Converter` class, you can define a converter for arbitrary
types.

Example:

```c++
#include "base/strings/string16.h"
#include "native_mate/converter.h"

namespace mate {

template<>
struct Converter<base::string16> {
  static v8::Handle<v8::Value> ToV8(v8::Isolate* isolate,
                                    const base::string16& val) {
    return MATE_STRING_NEW_FROM_UTF16(
        isolate, reinterpret_cast<const uint16_t*>(val.data()), val.size());
  }
  static bool FromV8(v8::Isolate* isolate,
                     v8::Handle<v8::Value> val,
                     base::string16* out) {
    if (!val->IsString())
      return false;

    v8::String::Value s(val);
    out->assign(reinterpret_cast<const base::char16*>(*s), s.length());
    return true;
  }
};

}  // namespace mate
```
