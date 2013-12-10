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
	double angle = 0;
	if (args.Length() == 4) {
		id = collision->move_segment((double)args[0]->NumberValue(),
			(double)args[1]->NumberValue(),
			(double)args[2]->NumberValue(),
			(double)args[3]->NumberValue());
	} else if (args.Length() == 5){
		Local<Function> cb = Local<Function>::Cast(args[4]);
		const unsigned argc = 2;
		collision->move_segment((double)args[0]->NumberValue(),
			(double)args[1]->NumberValue(),
			(double)args[2]->NumberValue(),
			(double)args[3]->NumberValue(),
			&id,
			&angle);	
		Local<Value> argv[argc] = {Local<Value>::New(Number::New(id)),
									Local<Value>::New(Number::New(angle))};
		cb->Call(Context::GetCurrent()->Global(),argc,argv);
	}
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
