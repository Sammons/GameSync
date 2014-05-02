#include "project.h"

using namespace v8;
using namespace std;

typedef Local<Number> localNum; 
typedef String::Utf8Value v8String;


float32 getValueAsNumber(Local<Value> arg) {
	return (localNum::Cast(arg))->NumberValue();
}

string getValueAsString(Local<Value> arg) {
	return string(*(v8String(arg)));
}

Persistent<Function> getValueAsPersistentFunction(Local<Value> arg) {
	return Persistent<Function>::New(Local<Function>::Cast(arg));
}

Local<Function> getValueAsFunction(Local<Value> arg) {
	return Local<Function>::Cast(arg);
}

namespace globals {
	b2World *world;
	map<string, b2Body*> bodies;
}


namespace boxCreators {

	Handle<Value> CreateWorld(const Arguments& args) {
		HandleScope scope;

		//we like that gravity thing // TODO make argument customize
		b2Vec2 gravity(
			  getValueAsNumber(args[0])
			, getValueAsNumber(args[1])
		);

		//TODO: research if there are conditions where we might
		//need multiple worlds
		globals::world = new b2World(gravity);

		return scope.Close(Undefined());
	}

	Handle<Value> CreateDynamicBody(const Arguments& args) {
		HandleScope scope;

		//TODO manage other numbers of arguments
		if (!args.Length() == 7) {
		    printf("%s\n", "wrong number of args to CreateDynamicBody"); 
			return Undefined();
		}

		float32 x   = getValueAsNumber(args[0]);
		float32 y   = getValueAsNumber(args[1]);
		string  name = getValueAsString(args[2]);
		
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;

		bodyDef.position.Set(x, y);
		
		bodyDef.createCallback = getValueAsPersistentFunction(args[3]);
		bodyDef.updateCallback = getValueAsPersistentFunction(args[4]);
		bodyDef.collideCallback = getValueAsPersistentFunction(args[5]);
		bodyDef.destroyCallback = getValueAsPersistentFunction(args[6]);

		b2Body* body = globals::world->CreateBody(&bodyDef);
		globals::bodies.insert(std::make_pair(name, body));

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

}