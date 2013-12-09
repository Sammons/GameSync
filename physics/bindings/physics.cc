#include <node.h>
#include <v8.h>

using namespace v8;

int i = 0;

Handle<Value> Method(const Arguments& args) {
	HandleScope scope;
	printf("Physics system started.\n");
	return scope.Close(String::New("hi"));
}

void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("initialize"),
		FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(physics,init)