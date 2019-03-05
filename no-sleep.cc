#ifdef WIN32 
#include <node.h>

namespace nosleep {

using node::AtExit;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::NewStringType;
using v8::Object;
using v8::String;
using v8::Value;
//BluetoothAPIs.h depends on these.
#include <Winsock2.h>
#include <Ws2bth.h>

#include <BluetoothAPIs.h>
#pragma comment(lib, "Bthprops.lib")

void PreventSleep(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED) != NULL);
}

void AllowSleep(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(SetThreadExecutionState(ES_CONTINUOUS) != NULL);
}

void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "preventSleep", PreventSleep);
  NODE_SET_METHOD(exports, "allowSleep", AllowSleep);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}
#endif
