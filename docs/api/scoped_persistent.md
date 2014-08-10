# ScopedPersistent

The `scoped_persistent.h` provides some C++ helper classes for managing
persistent V8 handles.

## References

### `template <typename T> ScopedPersistent(v8::Isolate* isolate, v8::Handle<v8::Value> handle)`

Creates a `ScopedPersistent` that wraps around `handle`.

The `ScopedPersistent` is not copiable and would release the handle when
destructed.

### `void ScopedPersistent<T>::reset(v8::Isolate* isolate, v8::Handle<T> handle)`

Releases current handle and stores the `handle` instead.

### `void ScopedPersistent<T>::reset()`

Releases current handle.

### `bool ScopedPersistent<T>::IsEmpty() const`

Returns whether current handle is empty.

### `v8::Handle<T> ScopedPersistent<T>::NewHandle(v8::Isolate* isolate) const`

Returns a local handle form current persistent handle.

### `template <typename T> RefCountedPersistent(v8::Isolate* isolate, v8::Handle<v8::Value> handle)`

Creates a `RefCountedPersistent` that wraps around `handle`.

The `RefCountedPersistent` is like `ScopedPersistent` except that the lifetime
is managed via the `base::RefCounted` interface. With `scoped_refptr` it can
make a persistent V8 handle safely copiable.

For usages of ref counted pointers, see
[ref_counted.h](https://github.com/zcbenz/base-minimal/blob/master/src/base/memory/ref_counted.h).
