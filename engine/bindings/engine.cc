#include <node.h>
#include <v8.h>
#include "src/wrapper.h"
//not sure what to call the adapter-lib between this file and the rest that interact/wrap Box
#include <time.h>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace v8;

b2World *world;
std::map<std::string, b2Body*> bodies;


void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

// gravity vector?
Handle<Value> CreateWorld(const Arguments& args) {
	HandleScope scope;
	return scope.Close(Undefined());
}
Handle<Value> CreateDynamicBody(const Arguments& args) {
	HandleScope scope;
	return scope.Close(Undefined());
}

Handle<Value> CreateFixedBody(const Arguments& args) {
	HandleScope scope;
	return scope.Close(Undefined());
}
Handle<Value> AttachDynamicBoxFixture(const Arguments& args) {
	HandleScope scope;
	return scope.Close(Undefined());
}
Handle<Value> AttachFixedBoxFixture(const Arguments& args) {
	HandleScope scope;
	return scope.Close(Undefined());
}
Handle<Value> Tick(const Arguments& args) {
	HandleScope scope;
	return scope.Close(Undefined());
}
Handle<Value> Update(const Arguments& args) {
	HandleScope scope;
	world->UpdateBodies();
	return scope.Close(Undefined());
}

void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("CreateWorld"),
		FunctionTemplate::New(CreateWorld)->GetFunction());
	exports->Set(String::NewSymbol("CreateDynamicBody"),
		FunctionTemplate::New(CreateDynamicBody)->GetFunction());
	exports->Set(String::NewSymbol("CreateFixedBody"),
		FunctionTemplate::New(CreateFixedBody)->GetFunction());
	exports->Set(String::NewSymbol("AttachDynamicBoxFixture"),
		FunctionTemplate::New(AttachDynamicBoxFixture)->GetFunction());
	exports->Set(String::NewSymbol("AttachFixedBoxFixture"),
		FunctionTemplate::New(AttachFixedBoxFixture)->GetFunction());//TODO
	exports->Set(String::NewSymbol("Tick"),
		FunctionTemplate::New(Tick)->GetFunction());
	exports->Set(String::NewSymbol("Update"),
		FunctionTemplate::New(Update)->GetFunction());
}

NODE_MODULE(engine,init)
