#include "Shape.h"

Shape::Shape(double x, double y, double angle,long time,int id, v8::Local<v8::Function> collisionHandler)
	:position(x, y), orientationAngle(angle), orientationVector(0, 1), motionVector(0, 0), motionAngle(0), id(id) {

	orientationVector.applyAngle(angle);

	this->collisionHandler = collisionHandler;
}

Shape::~Shape() {
	
}

void Shape::addToPath(Segment segment) {
	this->PathSegments.push_back(segment);
}

void Shape::handleCollision(const std::string &type) {
	const unsigned argc = 1;
	v8::Local<v8::Value> argv[argc] = {v8::Local<v8::Value>::New(v8::String::New(type.c_str()))};
	this->collisionHandler->Call(v8::Context::GetCurrent()->Global(),argc, argv);
}

vector<Segment> Shape::getField(long time) const {
	return drawBody(time);
}

//generates segments that define the collision body about a point that is the center of mass
vector<Segment> Shape::drawBody(long time) const {
	Coord position = getPosition(time);

	return drawSquare(position, time, 15);
}

vector<Segment> Shape::drawSquare(Coord center, long time, int sideLength) const {
	double sideOffset = sideLength / 2;
	
	//square drawn clockwise starting at the top left corner
	Coord topLeft(position.x - sideOffset, position.y + sideOffset),
		topRight(position.x + sideOffset, position.y + sideOffset),
		bottomRight(position.x + sideOffset, position.y - sideOffset),
		bottomLeft(position.x - sideOffset, position.y - sideOffset);

	vector<Segment> body;

	body.push_back(Segment(topLeft, topRight, time, id));
	body.push_back(Segment(topRight, bottomRight, time, id));
	body.push_back(Segment(bottomRight, bottomLeft, time, id));
	body.push_back(Segment(bottomLeft, topLeft, time, id));
	
	return body;
}

Coord Shape::getPosition(long time) const {
	if (motionVector == Coord(0, 0))
		return this->position;

	long deltaT = this->currentTime - time;
	//pretend there is only linear constant motion
	return position + (motionVector * deltaT);
}

Coord Shape::getMotionVector() {
	return this->motionVector;
}

std::string Shape::ToString() {
	return " properties not implemented yet!\n";
}