#include <node.h>
#include <v8.h>
#include "src/wrapper.h"
//not sure what to call the adapter-lib between this file and the rest that interact/wrap Box
using namespace v8;

//testing Box2D
Handle<Value> HelloWorld(const Arguments& args) {
	HandleScope scope;
	HelloWorld();
	return scope.Close(Undefined());
}

// gravity vector?
Handle<Value> CreateWorld(const Arguments& args) {
	HandleScope scope;
	//TODO want to return the world: http://nodejs.org/api/addons.html#addons_wrapping_c_objects

	return scope.Close(Undefined());
}

void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("HelloWorld"),
		FunctionTemplate::New(HelloWorld)->GetFunction());
	exports->Set(String::NewSymbol("CreateWorld"),
		FunctionTemplate::New(CreateWorld)->GetFunction());
}

NODE_MODULE(engine,init)
