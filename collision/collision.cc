#include <node.h>
#include <v8.h>

using namespace v8;

int i = 0;

Handle<Value> Method(const Arguments& args) {
	HandleScope scope;
	printf("%d\n", i);
	i++;
	return scope.Close(String::New("hi"));
}

void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("count"),
		FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(collision,init)
