# ObjectTemplateBuilder

The `object_template_builder.h` provides the `ObjectTemplateBuilder` class for
building `v8::Object` easily.

## References

### `ObjectTemplateBuilder(v8::Isolate* isolate)`

Creates an empty `ObjectTemplateBuilder`.

### `ObjectTemplateBuilder(v8::Isolate* isolate, v8::Local<v8::ObjectTemplate> templ)`

Creates an `ObjectTemplateBuilder` that manipulates the `templ`.

### `template<typename T> ObjectTemplateBuilder& ObjectTemplateBuilder::SetValue(const base::StringPiece& name, T val)`

Sets the property to `value`.

The `ObjectTemplateBuilder` itself is returned so calls can be chained, like
this:

```c++
mate::ObjectTemplateBuilder MyClass::GetObjectTemplateBuilder(
     v8::Isolate* isolate) {
  return mate::ObjectTemplateBuilder(isolate)
      .SetValue("name", "時計")
      .SetValue("price", 3000);
```

### `template<typename T> ObjectTemplateBuilder& ObjectTemplateBuilder::SetMethod(const base::StringPiece& name, const T& callback)`

Sets the property to `callback`.

The `callback` can be function pointer, member function pointer,
`base::Callback`, or `v8::FunctionTemplate`. Most clients will want to use one
of the first two options.

When the `callback` is a member function pointer, native-mate will automatically
convert the `this` object of JavaScript to the corresponding C++ pointer, so
users can easily bind C++ class's member functions to JavaScript.

### `template<typename T> ObjectTemplateBuilder& ObjectTemplateBuilder::SetProperty(const base::StringPiece& name, const T& getter)`

Sets `getter` for the property.

__Note:__ This is not working for node < 0.11.x.

### `template<typename T, typename U> ObjectTemplateBuilder& ObjectTemplateBuilder::SetProperty(const base::StringPiece& name, const T& getter, const U& setter)`

Sets `getter` and `setter` for the property.

__Note:__ This is not working for node < 0.11.x.

### `v8::Local<v8::ObjectTemplate> ObjectTemplateBuilder::Build()`

Builds and returns an `v8::ObjectTemplate`.
