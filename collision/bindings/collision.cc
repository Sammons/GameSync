#include "./src/collision.cpp"
#include <node.h>
#include <v8.h>


using namespace v8;

Handle<Value> Initialize(const Arguments& args) {
	HandleScope scope;

	return scope.Close(String::New("hi"));
}
Handle<Value> Destroy(const Arguments& args) {
	HandleScope scope;

	return scope.Close(String::New("goodbye"));
}

void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("initialize"),
		FunctionTemplate::New(Initialize)->GetFunction());
	exports->Set(String::NewSymbol("destroy"),
		FunctionTemplate::New(Destroy)->GetFunction());
}

NODE_MODULE(collision,init)
