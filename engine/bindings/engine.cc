#include <node.h>
#include <v8.h>
#include "src/common.h"
#include "src/Scene.h"
#include "src/Box2D/Box2D.h"
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
	// Define the gravity vector.
	b2Vec2 gravity(0.0f, -10.0f);

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
	bodyDef.position.Set(0.0f, 4.0f);
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

	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);

	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	// This is our little game loop.
	for (int32 i = 0; i < 60; ++i)
	{
		// Instruct the world to perform a single step of simulation.
		// It is generally best to keep the time step and iterations fixed.
		world.Step(timeStep, velocityIterations, positionIterations);

		// Now print the position and angle of the body.
		b2Vec2 position = body->GetPosition();
		float32 angle = body->GetAngle();

		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
	}

	// When the world destructor is called, all bodies and joints are freed. This can
	// create orphaned pointers, so be careful about your world management.
	return scope.Close(Number::New(1));
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
