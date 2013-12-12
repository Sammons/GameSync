#include <node.h>
#include <v8.h>
#include "./src/common.h"
#include "./src/Scene.cpp"
using namespace v8;

Scene* world;
int id;
Handle<Value> Initialize(const Arguments& args) {
	HandleScope scope;
	id = 0;
	double mapHeight = (args[0]->IsNumber()?(double)args[0]->NumberValue():500);
	double mapWidth = (args[1]->IsNumber()?(double)args[1]->NumberValue():500);
	int boundaryType = (args[2]->IsNumber()?(int)args[2]->NumberValue():BOUNDARY_BLOCKING);
	int predictionLength = (args[3]->IsNumber()?(int)args[3]->NumberValue():20);
	Local<Function> cb = Local<Function>::Cast(args[4]);
	world = new Scene(mapHeight,mapWidth,boundaryType,predictionLength,cb);
	return scope.Close(Undefined());
}
Handle<Value> Destroy(const Arguments& args) {
	HandleScope scope;
	delete(world);
	return scope.Close(Undefined());
}
Handle<Value> AddSegment(const Arguments& args) {
	HandleScope scope;
	id++;
	return scope.Close(Number::New(id));
}

Handle<Value> AddShape(const Arguments& args) {
	HandleScope scope;
	double x1 = (double)args[0]->NumberValue();
	double y1 = (double)args[1]->NumberValue();
	double angle = (double)args[2]->NumberValue();
	Local<Function> collisionHandler = Local<Function>::Cast(args[3]);
	world->addShape(Shape(x1,y1,angle,world->getTime(),id,collisionHandler));
	Local<Function> cb = Local<Function>::Cast(args[4]);
	const unsigned argc = 1;
	id = id + 1;
	Local<Value> argv[argc] = {Local<Value>::New(Number::New(id))};
	cb->Call(Context::GetCurrent()->Global(), argc, argv);
	return scope.Close(argv[0]);
}

Handle<Value> Tick(const Arguments& args) {
	HandleScope scope;
	world->tick(1);
	return scope.Close(Undefined());
}

void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("initialize"),
		FunctionTemplate::New(Initialize)->GetFunction());
	exports->Set(String::NewSymbol("destroy"),
		FunctionTemplate::New(Destroy)->GetFunction());
	exports->Set(String::NewSymbol("addSegment"),
		FunctionTemplate::New(AddSegment)->GetFunction());
	exports->Set(String::NewSymbol("addShape"),
		FunctionTemplate::New(AddShape)->GetFunction());
	exports->Set(String::NewSymbol("Tick"),
		FunctionTemplate::New(AddShape)->GetFunction());
}

NODE_MODULE(engine,init)
