// Copyright 2014 Cheng Zhao. All rights reserved.
// Use of this source code is governed by MIT license that can be found in the
// LICENSE file.

#ifndef NATIVE_MATE_COMPAT_H_
#define NATIVE_MATE_COMPAT_H_

#if (NODE_MODULE_VERSION > 0x000B) // Node 0.11+

#define MATE_METHOD_ARGS_TYPE   v8::FunctionCallbackInfo<v8::Value>
#define MATE_METHOD_RETURN_TYPE void

#define MATE_METHOD_SCOPE(isolate)      // nop
#define MATE_METHOD_RETURN_VALUE(value) return args.GetReturnValue().Set(value)
#define MATE_METHOD_RETURN_UNDEFINED()  return
#define MATE_METHOD_RETURN_NULL()       return args.GetReturnValue().SetNull()

#define MATE_SET_INTERNAL_FIELD_POINTER(object, index, value) \
    object->SetAlignedPointerInInternalField(index, value)
#define MATE_GET_INTERNAL_FIELD_POINTER(object, index) \
    object->GetAlignedPointerFromInternalField(index)

#define MATE_PERSISTENT_ASSIGN(type, isolate, handle, object) \
    handle.Reset(isolate, object)
#define MATE_PERSISTENT_DISPOSE(handle) \
    handle.Reset()
#define MATE_PERSISTENT_TO_LOCAL(type, isolate, handle) \
    v8::Local<type>::New(isolate, handle)

#else  // Node 0.8 and 0.10

#define MATE_METHOD_ARGS_TYPE   v8::Arguments
#define MATE_METHOD_RETURN_TYPE v8::Handle<v8::Value>

#define MATE_METHOD_SCOPE(isolate)      v8::HandleScope scope
#define MATE_METHOD_RETURN_VALUE(value) return scope.Close(value)
#define MATE_METHOD_RETURN_UNDEFINED()  return v8::Undefined()
#define MATE_METHOD_RETURN_NULL()       return v8::Null()

#define MATE_SET_INTERNAL_FIELD_POINTER(object, index, value) \
    object->SetPointerInInternalField(index, value)
#define MATE_GET_INTERNAL_FIELD_POINTER(object, index) \
    object->GetPointerFromInternalField(index)

#define MATE_PERSISTENT_ASSIGN(type, isolate, handle, object) \
    handle = v8::Persistent<type>::New(obj)
#define MATE_PERSISTENT_DISPOSE(handle) \
    handle.Dispose() \
    handle.Clear()
#define MATE_PERSISTENT_TO_LOCAL(type, isolate, handle) \
    v8::Local<type>::New(handle)

#endif  // (NODE_MODULE_VERSION > 0x000B)


#define MATE_METHOD(name) \
    MATE_METHOD_RETURN_TYPE name(const MATE_METHOD_ARGS_TYPE& args)
#define MATE_METHOD_RETURN(value) \
    MATE_METHOD_RETURN_VALUE(ConvertToV8(args.GetIsolate(), val))

#define MATE_THROW_EXCEPTION(type, message) \
    v8::ThrowException(type(v8::String::New(message)))
#define MATE_THROW_ERROR(message) \
    MATE_THROW_EXCEPTION(v8::Exception::Error, message)
#define MATE_THROW_TYPE_ERROR(message) \
    MATE_THROW_EXCEPTION(v8::Exception::TypeError, message)
#define MATE_THROW_SYNTAX_ERROR(message) \
    MATE_THROW_EXCEPTION(v8::Exception::SyntaxError, message)

#endif  // NATIVE_MATE_COMPAT_H_
