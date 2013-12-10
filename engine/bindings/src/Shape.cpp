#include "Shape.h"

Shape::Shape(double x, double y, double angle,long time, Local<Function> collisionHandler) {
	this->position = new Coord(x,y);
	this->orientationAngle = angle;
	Coord* orientationVector = (new Coord(0,1));
	orientationVector->applyAngle(angle);
	this->orientationVector = orientationVector;
	this->motionVector = new Coord(0,0);
	this->motionAngle = 0;
	this->collisionHandler = collisionHandler;
}

Shape::~Shape() {
	
}

void Shape::addToPath(Segment* segment) {
	this->PathSegments.push_back(segment);
}

void Shape::handleCollision(const char* type) {
	const unsigned argc = 1;
	Local<Value> argv[argc] = {Local<Value>::New(String::New(type))};
	this->collisionHandler->Call(Context::GetCurrent()->Global(),argc, argv);
}