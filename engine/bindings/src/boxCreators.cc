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

// the level of bastardization this achieves is awesome
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

		return True();
	}

	Handle<Value> CreateDynamicBody(const Arguments& args) {
		HandleScope scope;

		//TODO manage other numbers of arguments
		if (!(args.Length() == 7)) {
		    printf("%s\n", "wrong number of args to CreateDynamicBody"); 
			return False();
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

		return True();
	}

	Handle<Value> CreateFixedBody(const Arguments& args) {
		HandleScope scope;

		//TODO manage other numbers of arguments
		if (!(args.Length() == 7)) {
		    printf("%s\n", "wrong number of args to CreateDynamicBody"); 
			return False();
		} 

		float32 x = getValueAsNumber(args[0]);
		float32 y = getValueAsNumber(args[1]);
		string name = getValueAsString(args[2]);
		// cout << "creating fixed body " << name << " at " << x << " and " << y;

		b2BodyDef bodyDef;

		bodyDef.createCallback = getValueAsPersistentFunction(args[3]);
		bodyDef.updateCallback = getValueAsPersistentFunction(args[4]);
		bodyDef.collideCallback = getValueAsPersistentFunction(args[5]);
		bodyDef.destroyCallback = getValueAsPersistentFunction(args[6]);
		bodyDef.position.Set(x, y);

		b2Body* body = globals::world->CreateBody(&bodyDef);
		globals::bodies.insert(std::make_pair(name, body));

		return True();
	}

	Handle<Value> AttachDynamicBoxFixture(const Arguments& args) {

		//TODO manage other numbers of arguments
		if (!(args.Length() == 6)) {
		    printf("%s\n", "wrong number of args to CreateDynamicBody"); 
			return False();
		}
		string name     = getValueAsString(args[0]);
		float32 width   = getValueAsNumber(args[1]);
		float32 height 	= getValueAsNumber(args[2]);
		float32 density 	= getValueAsNumber(args[3]);
		float32 friction 	= getValueAsNumber(args[4]);
		float32 restitution = getValueAsNumber(args[5]);
		
		//TODO -- this should not necessarily be a default
		bool collidable = true;
		
		auto bodies_iterator = globals::bodies.find(name);
		
		if (bodies_iterator != globals::bodies.end()) {
			//get the body to attach to
			auto body = bodies_iterator->second;//first is the string, second is the body

			//create the shape
			b2PolygonShape shape;
			shape.SetAsBox(width/2, height/2 );//b2Vec2(,x,y), theta);//divide by two since this takes half widths
			
			//frame up the fixture definition
			b2FixtureDef boxFixtureDefinition;

			boxFixtureDefinition.shape 			= &shape;
			boxFixtureDefinition.density 		= density;
			boxFixtureDefinition.friction 		= friction;
			boxFixtureDefinition.restitution 	= restitution;
			// boxFixtureDefinition.isSensor 		= collidable;
			
			//attach the fixture
			body->CreateFixture(&boxFixtureDefinition);
		}
		HandleScope scope;
		return True();
	}

	Handle<Value> AttachFixedBoxFixture(const Arguments& args) {
		HandleScope scope;
		//get height and width and object name
		string name = getValueAsString(args[0]);
		float32 width = getValueAsNumber(args[1]);
		float32 height 	= getValueAsNumber(args[2]);

		auto bodies_iterator = globals::bodies.find(name);
		
		if (bodies_iterator != globals::bodies.end()) {
			//get the body to attach to
			auto body = bodies_iterator->second;//first is the string, second is the body

			//create the shape
			b2PolygonShape box;
			box.SetAsBox(width/2, height/2 );//b2Vec2(,x,y), theta);//divide by two since this takes half widths
			body->CreateFixture(&box,0);
		}
		return True();
	}

}