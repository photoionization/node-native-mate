#include "native_mate/arguments.h"
#include "native_mate/callback.h"
#include "native_mate/constructor.h"
#include "native_mate/converter.h"
#include "native_mate/dictionary.h"
#include "native_mate/function_template.h"
#include "native_mate/handle.h"
#include "native_mate/object_template_builder.h"
#include "native_mate/scoped_persistent.h"
#include "native_mate/try_catch.h"
#include "native_mate/wrappable.h"
#include "native_mate/wrappable.h"

void TestCompilation() {
  v8::Isolate* isolate = v8::Isolate::GetCurrent();

  mate::Arguments arguments;
  mate::Dictionary dictionary(isolate);
  mate::CreateFunctionTemplate(isolate, base::Bind(TestCompilation));
  mate::ConvertFromV8(isolate, MATE_OBJECT_NEW(isolate), &dictionary);
  mate::ScopedPersistent<v8::Object> object(MATE_OBJECT_NEW(isolate), isolate);

  base::Closure callback;
  mate::ConvertFromV8(isolate, MATE_OBJECT_NEW(isolate), &callback);
  mate::ConvertToV8(isolate, base::Bind(&TestCompilation));
}
