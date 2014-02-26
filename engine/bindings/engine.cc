#include <node.h>
#include <v8.h>
#include "src/wrapper.h"
#include <time.h>
//not sure what to call the adapter-lib between this file and the rest that interact/wrap Box
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

//testing Box2D
Handle<Value> HelloWorld(const Arguments& args) {
	HandleScope scope;
	Local<Function> cb = Local<Function>::Cast(args[0]);
	const unsigned argc = 1;
	

	b2Vec2 gravity(0.0f, -20.0f);

	// Construct a world object, which will hold and simulate the rigid bodies.
	b2World world(gravity);

	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(50.0f, 10.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 8.0f);
	b2Body* body = world.CreateBody(&bodyDef);

	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// Override the default friction.
	fixtureDef.friction = 0.3f;

	// make it bounce
	fixtureDef.restitution = 0.5f;

	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);

	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	// This is our little game loop.
	for (int32 i = 0; i < 300; ++i)
	{
		sleep(250);
		// Instruct the world to perform a single step of simulation.
		// It is generally best to keep the time step and iterations fixed.
		world.Step(timeStep, velocityIterations, positionIterations);

		// Now print the position and angle of the body.
		b2Vec2 position = body->GetPosition();
		Local<Value> argv[argc] = {Local<Value>::New(Number::New(position.y))};
		cb->Call(Context::GetCurrent()->Global(), argc, argv);
		//printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
	}
	return scope.Close(Undefined());
}

// gravity vector?
Handle<Value> CreateWorld(const Arguments& args) {
	HandleScope scope;
	b2Vec2 gravity((Local<Number>::Cast(args[0]))->NumberValue(), (Local<Number>::Cast(args[1]))->NumberValue());

	// Construct a world object, which will hold and simulate the rigid bodies.
	world = new b2World(gravity);

	// b2BodyDef groundBodyDef;
	// groundBodyDef.position.Set(0.0f, -10.0f);
	// b2Body* groundBody = world->CreateBody(&groundBodyDef);

	// // Define the ground box shape.
	// b2PolygonShape groundBox;

	// // The extents are the half-widths of the box.
	// groundBox.SetAsBox(50.0f, 5.0f);

	// // Add the ground fixture to the ground body.
	// groundBody->CreateFixture(&groundBox, 0.0f);

	// // Define the dynamic body. We set its position and call the body factory.
	// b2BodyDef bodyDef;
	// //bodyDef.type = b2_dynamicBody;
	// bodyDef.position.Set(0.0f, 8.0f);
	// b2Body* body = world->CreateBody(&bodyDef);

	return scope.Close(Undefined());
}
Handle<Value> CreateDynamicBody(const Arguments& args) {
	HandleScope scope;
	//get x and y and object name
	float32 x = (Local<Number>::Cast(args[0]))->NumberValue();
	float32 y = (Local<Number>::Cast(args[1]))->NumberValue();
	v8::String::Utf8Value arg1(args[2]->ToString());
	std::string name = std::string(*arg1);
	
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);

	b2Body* body = world->CreateBody(&bodyDef);

	body->SetCreateCallback(Persistent<Function>::New(Local<Function>::Cast(args[3])));
	body->SetUpdateCallback(Persistent<Function>::New(Local<Function>::Cast(args[4])));
	body->SetCollideCallback(Persistent<Function>::New(Local<Function>::Cast(args[5])));
	body->SetDestroyCallback(Persistent<Function>::New(Local<Function>::Cast(args[6])));

	bodies.insert(std::make_pair(name, body));
	
	return scope.Close(Undefined());
}

Handle<Value> CreateFixedBody(const Arguments& args) {
	HandleScope scope;
	//get x and y and object name
	float32 x = (Local<Number>::Cast(args[0]))->NumberValue();
	float32 y = (Local<Number>::Cast(args[1]))->NumberValue();
	v8::String::Utf8Value arg1(args[2]->ToString());
	std::string name = std::string(*arg1);
	
	b2BodyDef bodyDef;
	bodyDef.position.Set(x, y);
	b2Body* body = world->CreateBody(&bodyDef);

	body->SetCreateCallback(Persistent<Function>::New(Local<Function>::Cast(args[3])));
	body->SetUpdateCallback(Persistent<Function>::New(Local<Function>::Cast(args[4])));
	body->SetCollideCallback(Persistent<Function>::New(Local<Function>::Cast(args[5])));
	body->SetDestroyCallback(Persistent<Function>::New(Local<Function>::Cast(args[6])));
	
	bodies.insert(std::make_pair(name, body));
	
	return scope.Close(Undefined());
}
//name, width, height, x, y, angle, density, friction, restitution
Handle<Value> AttachDynamicBoxFixture(const Arguments& args) {
	HandleScope scope;
	//get height and width and object name
	v8::String::Utf8Value arg0(args[0]->ToString());
	std::string name = std::string(*arg0);
	float32 width 		= (Local<Number>::Cast(args[1]))->NumberValue();
	float32 height 		= (Local<Number>::Cast(args[2]))->NumberValue();
	float32 x 			= (Local<Number>::Cast(args[3]))->NumberValue();
	float32 y 			= (Local<Number>::Cast(args[4]))->NumberValue();
	float32 theta 		= (Local<Number>::Cast(args[5]))->NumberValue();
	float32 density 		= (Local<Number>::Cast(args[6]))->NumberValue();
	float32 friction 		= (Local<Number>::Cast(args[7]))->NumberValue();
	float32 restitution 	= (Local<Number>::Cast(args[8]))->NumberValue();
	
	bool collidable = true;
	
	auto bodies_iterator = bodies.find(name);
	
	if (bodies_iterator != bodies.end()) {
		//get the body to attach to
		auto body = bodies_iterator->second;//first is the string, second is the body

		//create the shape
		b2PolygonShape box;
		box.SetAsBox(width/2, height/2 );//b2Vec2(,x,y), theta);//divide by two since this takes half widths
		
		//frame up the fixture definition
		b2FixtureDef boxFixtureDefinition;

		boxFixtureDefinition.shape 			= &box;
		boxFixtureDefinition.density 		= density;
		boxFixtureDefinition.friction 		= friction;
		boxFixtureDefinition.restitution 	= restitution;
		//boxFixtureDefinition.isSensor 		= collidable;
		
		//attach the fixture
		body->CreateFixture(&boxFixtureDefinition);
	}
	return scope.Close(Undefined());
}
Handle<Value> AttachFixedBoxFixture(const Arguments& args) {
	HandleScope scope;

	//get height and width and object name
	v8::String::Utf8Value arg0(args[0]->ToString());
	std::string name = std::string(*arg0);
	float32 width 		= (Local<Number>::Cast(args[1]))->NumberValue();
	float32 height 		= (Local<Number>::Cast(args[2]))->NumberValue();

	auto bodies_iterator = bodies.find(name);
	
	if (bodies_iterator != bodies.end()) {
		//get the body to attach to
		auto body = bodies_iterator->second;//first is the string, second is the body

		//create the shape
		b2PolygonShape box;
		box.SetAsBox(width/2, height/2 );//b2Vec2(,x,y), theta);//divide by two since this takes half widths
		body->CreateFixture(&box,0);
	}
	return scope.Close(Undefined());
}
Handle<Value> Tick(const Arguments& args) {
	HandleScope scope;
	// It is generally best to keep the time step and iterations fixed.
	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	world->Step(timeStep, velocityIterations, positionIterations);
	return scope.Close(Undefined());
}
Handle<Value> Update(const Arguments& args) {
	HandleScope scope;
	world->UpdateBodies();
	return scope.Close(Undefined());
}

void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("HelloWorld"),
		FunctionTemplate::New(HelloWorld)->GetFunction());

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
