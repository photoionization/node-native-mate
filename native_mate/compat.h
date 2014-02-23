// Copyright 2014 Cheng Zhao. All rights reserved.
// Use of this source code is governed by MIT license that can be found in the
// LICENSE file.

#ifndef NATIVE_MATE_COMPAT_H_
#define NATIVE_MATE_COMPAT_H_

#include "node_version.h"

#if (NODE_MODULE_VERSION > 0x000B) // Node 0.11+

#define MATE_METHOD_ARGS_TYPE   v8::FunctionCallbackInfo<v8::Value>
#define MATE_METHOD_RETURN_TYPE void

#define MATE_METHOD_RETURN_VALUE(value) return info.GetReturnValue().Set(value)
#define MATE_METHOD_RETURN_UNDEFINED()  return
#define MATE_METHOD_RETURN_NULL()       return info.GetReturnValue().SetNull()
#define MATE_METHOD_RETURN(value)       args.Return(value)

#define MATE_STRING_NEW_FROM_UTF8(isolate, data, length) \
    v8::String::NewFromUtf8(isolate, data, v8::String::kNormalString, length)
#define MATE_STRING_NEW_SYMBOL(isolate, data, length) \
    v8::String::NewFromUtf8(isolate, data, v8::String::kInternalizedString, length)

#define MATE_SET_INTERNAL_FIELD_POINTER(object, index, value) \
    object->SetAlignedPointerInInternalField(index, value)
#define MATE_GET_INTERNAL_FIELD_POINTER(object, index) \
    object->GetAlignedPointerFromInternalField(index)

#define MATE_PERSISTENT_INIT(isolate, handle, value) \
    handle(isolate, value)
#define MATE_PERSISTENT_ASSIGN(type, isolate, handle, value) \
    handle.Reset(isolate, value)
#define MATE_PERSISTENT_DISPOSE(handle) \
    handle.Reset()
#define MATE_PERSISTENT_TO_LOCAL(type, isolate, handle) \
    v8::Local<type>::New(isolate, handle)
#define MATE_PERSISTENT_SET_WEAK(handle, parameter, callback) \
    handle.SetWeak(parameter, callback)

#else  // Node 0.8 and 0.10

#define MATE_METHOD_ARGS_TYPE   v8::Arguments
#define MATE_METHOD_RETURN_TYPE v8::Handle<v8::Value>

#define MATE_METHOD_RETURN_VALUE(value) return value
#define MATE_METHOD_RETURN_UNDEFINED()  return v8::Undefined()
#define MATE_METHOD_RETURN_NULL()       return v8::Null()
#define MATE_METHOD_RETURN(value) \
    MATE_METHOD_RETURN_VALUE(ConvertToV8(args.isolate(), value))

#define MATE_STRING_NEW_FROM_UTF8(isolate, data, length) \
    v8::String::New(data, length)
#define MATE_STRING_NEW_SYMBOL(isolate, data, length) \
    v8::String::NewSymbol(data, length)

#define MATE_SET_INTERNAL_FIELD_POINTER(object, index, value) \
    object->SetPointerInInternalField(index, value)
#define MATE_GET_INTERNAL_FIELD_POINTER(object, index) \
    object->GetPointerFromInternalField(index)

#define MATE_PERSISTENT_INIT(isolate, handle, value) \
    handle(value)
#define MATE_PERSISTENT_ASSIGN(type, isolate, handle, object) \
    handle = v8::Persistent<type>::New(obj)
#define MATE_PERSISTENT_DISPOSE(handle) \
    handle.Dispose() \
    handle.Clear()
#define MATE_PERSISTENT_TO_LOCAL(type, isolate, handle) \
    v8::Local<type>::New(handle)
#define MATE_PERSISTENT_SET_WEAK(handle, parameter, callback) \
    handle.MakeWeak(parameters, callback)

#endif  // (NODE_MODULE_VERSION > 0x000B)


#define MATE_METHOD(name) \
    MATE_METHOD_RETURN_TYPE name(const MATE_METHOD_ARGS_TYPE& info)

#define MATE_THROW_EXCEPTION(type, message) \
    v8::ThrowException(type(v8::String::New(message)))
#define MATE_THROW_ERROR(message) \
    MATE_THROW_EXCEPTION(v8::Exception::Error, message)
#define MATE_THROW_TYPE_ERROR(message) \
    MATE_THROW_EXCEPTION(v8::Exception::TypeError, message)
#define MATE_THROW_SYNTAX_ERROR(message) \
    MATE_THROW_EXCEPTION(v8::Exception::SyntaxError, message)

#endif  // NATIVE_MATE_COMPAT_H_
