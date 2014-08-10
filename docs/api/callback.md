# Callback

The `callback.h` provides an easy way to convert between C++ functions and
JavaScript functions.

## Prerequisites

* Read [base/callback.h](https://github.com/zcbenz/base-minimal/blob/master/src/base/callback.h)
  on the `base::Callback` type.
* Read [Converter](converter.md) on type convertions.

## Synopsis

Convert from V8 value to arbitrary function:

```C++
#include "native_mate/callback.h"

void CalledInJavaScript(v8::Isolate* isolate, v8::Handle<v8::Value> value) {
  base::Callback<void(std::string)> callback;
  if (mate::ConvertFromV8(isolate, value, &callback))
    callback.Run("ping");
}
```

Add a C++ method to V8 object:

```C++
#include "base/strings/stringprintf.h"
#include "native_mate/callback.h"
#include "native_mate/dictionary.h"

std::string IntegerToString(int number) {
  return base::StringPrintf("%d", number);
}

void CalledInJavaScript(v8::Isolate* isolate, v8::Handle<v8::Object> object) {
  mate::Dictionary dict(isolate, object);
  dict.Set("integerToString", base::Bind(&IntegerToString));
}
```
