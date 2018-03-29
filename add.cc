#include <nan.h>

using namespace v8;

void Add(const Nan::FunctionCallbackInfo<v8::Value> &info)
{

  if (info.Length() < 2)
  {
    Nan::ThrowTypeError("Wrong number of arguments <a,b>");
    return;
  }

  if (!info[0]->IsNumber() || !info[1]->IsNumber())
  {
    Nan::ThrowTypeError("Wrong Arguments , Arguments Must Be Numbers");
    return;
  }

  int arg0 = info[0]->NumberValue();
  int arg1 = info[1]->NumberValue();
  v8::Local<v8::Number> num = Nan::New(arg0 + arg1);

  info.GetReturnValue().Set(num);
}

void Multiply(const Nan::FunctionCallbackInfo<v8::Value> &info)
{

  if (info.Length() < 2)
  {
    Nan::ThrowTypeError("Wrong Number Of Arguments <a,b>");
    return;
  }
  if (!info[0]->IsNumber() || !info[1]->IsNumber())
  {
    Nan::ThrowTypeError("Wrong Arguments , Arguments Must Be Numbers");
    return;
  }
  int arg0 = info[0]->NumberValue();
  int arg1 = info[1]->NumberValue();
  v8::Local<v8::Number> num = Nan::New(arg0 * arg1);

  info.GetReturnValue().Set(num);
}

void Welcome(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  info.GetReturnValue().Set(Nan::New("Welcome From C++ Module").ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports)
{
  exports->Set(Nan::New("add").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Add)->GetFunction());
  exports->Set(Nan::New("welcome").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Welcome)->GetFunction());
  exports->Set(Nan::New("multiply").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Multiply)->GetFunction());
}

NODE_MODULE(add, Init)