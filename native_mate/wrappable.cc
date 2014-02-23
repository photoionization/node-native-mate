// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE.chromium file.

#include "native_mate/wrappable.h"

#include "base/logging.h"
#include "native_mate/object_template_builder.h"

namespace nm {

Wrappable::Wrappable() {
}

Wrappable::~Wrappable() {
  wrapper_.Reset();
}

ObjectTemplateBuilder Wrappable::GetObjectTemplateBuilder(
    v8::Isolate* isolate) {
  return ObjectTemplateBuilder(isolate);
}

void Wrappable::WeakCallback(
    const v8::WeakCallbackData<v8::Object, Wrappable>& data) {
  Wrappable* wrappable = data.GetParameter();
  wrappable->wrapper_.Reset();
  delete wrappable;
}

v8::Handle<v8::Object> Wrappable::GetWrapper(v8::Isolate* isolate) {
  if (!wrapper_.IsEmpty()) {
    return v8::Local<v8::Object>::New(isolate, wrapper_);
  }

  v8::Local<v8::ObjectTemplate> templ =
      GetObjectTemplateBuilder(isolate).Build();
  CHECK(!templ.IsEmpty());
  CHECK_EQ(1, templ->InternalFieldCount());
  v8::Handle<v8::Object> wrapper = templ->NewInstance();
  wrapper->SetAlignedPointerInInternalField(0, this);
  wrapper_.Reset(isolate, wrapper);
  wrapper_.SetWeak(this, WeakCallback);
  return wrapper;
}

namespace internal {

void* FromV8Impl(v8::Isolate* isolate, v8::Handle<v8::Value> val) {
  if (!val->IsObject())
    return NULL;
  v8::Handle<v8::Object> obj = v8::Handle<v8::Object>::Cast(val);
  return obj->GetAlignedPointerFromInternalField(0);
}

}  // namespace internal

}  // namespace nm
