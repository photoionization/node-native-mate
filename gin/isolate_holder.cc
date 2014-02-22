// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gin/public/isolate_holder.h"

#include <stdlib.h>
#include <string.h>

#include "gin/function_template.h"
#include "gin/per_isolate_data.h"

namespace gin {

namespace {

void EnsureV8Initialized(bool gin_managed) {
  static bool v8_is_initialized = false;
  static bool v8_is_gin_managed = false;
  if (v8_is_initialized) {
    CHECK_EQ(v8_is_gin_managed, gin_managed);
    return;
  }
  v8_is_initialized = true;
  v8_is_gin_managed = gin_managed;
  if (!gin_managed)
    return;

  static const char v8_flags[] = "--use_strict --harmony";
  v8::V8::SetFlagsFromString(v8_flags, sizeof(v8_flags) - 1);
  v8::V8::Initialize();
}

}  // namespace

IsolateHolder::IsolateHolder()
  : isolate_owner_(true) {
  EnsureV8Initialized(true);
  isolate_ = v8::Isolate::New();
  Init(NULL);
}

IsolateHolder::IsolateHolder(v8::Isolate* isolate)
    : isolate_owner_(false),
      isolate_(isolate) {
  EnsureV8Initialized(false);
  Init(NULL);
}

IsolateHolder::IsolateHolder(v8::Isolate* isolate,
                             v8::ArrayBuffer::Allocator* allocator)
    : isolate_owner_(false), isolate_(isolate) {
  EnsureV8Initialized(false);
  Init(allocator);
}

IsolateHolder::~IsolateHolder() {
  isolate_data_.reset();
  if (isolate_owner_)
    isolate_->Dispose();
}

void IsolateHolder::Init(v8::ArrayBuffer::Allocator* allocator) {
  v8::Isolate::Scope isolate_scope(isolate_);
  v8::HandleScope handle_scope(isolate_);
  isolate_data_.reset(new PerIsolateData(isolate_, allocator));
}

}  // namespace gin
