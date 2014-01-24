#include <node.h>
#include <v8.h>
#include "src/wrapper.h"
 #include <time.h>
//not sure what to call the adapter-lib between this file and the rest that interact/wrap Box
using namespace v8;

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
		float32 angle = body->GetAngle();
		Local<Value> argv[argc] = {Local<Value>::New(Number::New(position.y))};
		cb->Call(Context::GetCurrent()->Global(), argc, argv);
		//printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
	}
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
