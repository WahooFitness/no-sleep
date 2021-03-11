#ifdef WIN32 
#include <napi.h>
#include <windows.h>

Napi::Boolean PreventSleep(const Napi::CallbackInfo &info) {
  return Napi::Boolean::New(info.Env(), SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED) != NULL);
}

Napi::Boolean AllowSleep(const Napi::CallbackInfo &info) {
  return Napi::Boolean::New(info.Env(), SetThreadExecutionState(ES_CONTINUOUS) != NULL);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "preventSleep"),
    Napi::Function::New(env, PreventSleep));
  exports.Set(Napi::String::New(env, "allowSleep"),
    Napi::Function::New(env, AllowSleep));
}

NODE_API_MODULE(addon, Init)
#endif