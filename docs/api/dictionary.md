# Dictionary

The `dictionary.h` provides the `Dictionary` class for accessing `v8::Object`
easily.

Notice that `Dictionary` doesn't retain the V8 handle, so once the V8 handle
gets destroyed, you should free the corresponding `Dictionary` object too.

## Synopsis

```c++
#include "native_mate/dictionary.h"

v8::Handle<v8::Value> CalledInJavaScript(v8::Isolate* isolate) {
  mate::Dictionary dict(isolate, object);
  dict.Set("name", "Mike Ross");
  dict.Set("position", "Associate Lawyer");

  return mate::ConvertToV8(isolate, dict);
}
```

## References

### `Dictionary(v8::Isolate* isolate)`;

Creates an empty `Dictionary`.

### `Dictionary(v8::Isolate* isolate, v8::Handle<v8::Object> object)`;

Creates the `Dictionary` from `object`.

### `template<typename T> bool Dictionary::Get(const base::StringPiece& key, T* out) const`;

Reads the value of `key` property and saves to `out`.

### `template<typename T> bool Dictionary::Set(const base::StringPiece& key, T val)`;

Sets value of the `key` property to `val`.
