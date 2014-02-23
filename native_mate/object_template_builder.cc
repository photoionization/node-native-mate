// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "native_mate/object_template_builder.h"

namespace nm {

ObjectTemplateBuilder::ObjectTemplateBuilder(v8::Isolate* isolate)
    : isolate_(isolate), template_(v8::ObjectTemplate::New()) {
  template_->SetInternalFieldCount(1);
}

ObjectTemplateBuilder::~ObjectTemplateBuilder() {
}

ObjectTemplateBuilder& ObjectTemplateBuilder::SetImpl(
    const base::StringPiece& name, v8::Handle<v8::Data> val) {
  template_->Set(StringToSymbol(isolate_, name), val);
  return *this;
}

ObjectTemplateBuilder& ObjectTemplateBuilder::SetPropertyImpl(
    const base::StringPiece& name, v8::Handle<v8::FunctionTemplate> getter,
    v8::Handle<v8::FunctionTemplate> setter) {
  template_->SetAccessorProperty(StringToSymbol(isolate_, name), getter,
                                 setter);
  return *this;
}

v8::Local<v8::ObjectTemplate> ObjectTemplateBuilder::Build() {
  v8::Local<v8::ObjectTemplate> result = template_;
  template_.Clear();
  return result;
}

}  // namespace nm