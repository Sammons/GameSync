#include <node.h>
#include <v8.h>
#include "./src/dumb_collision.cpp"

using namespace v8;

dumb_collision* collision;

Handle<Value> Initialize(const Arguments& args) {
	HandleScope scope;
	collision = new dumb_collision();
	return scope.Close(String::New("hi"));
}
Handle<Value> Destroy(const Arguments& args) {
	HandleScope scope;
	delete(collision);
	return scope.Close(String::New("goodbye"));
}
Handle<Value> MoveSegment(const Arguments& args) {
	HandleScope scope;
	int id = -2;
	//int move_segment(double x, double y, int parent, int number);
	//id = collision->move_segment();
	return scope.Close(Number::New(id));
}

void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("initialize"),
		FunctionTemplate::New(Initialize)->GetFunction());
	exports->Set(String::NewSymbol("destroy"),
		FunctionTemplate::New(Destroy)->GetFunction());
	exports->Set(String::NewSymbol("moveSegment"),
		FunctionTemplate::New(MoveSegment)->GetFunction());
}

NODE_MODULE(collision,init)
