#include "Shape.h"

Shape::Shape(double x, double y, double angle,long time,int id, Local<Function> collisionHandler) {
	this->position = new Coord(x,y);
	this->orientationAngle = angle;
	Coord* orientationVector = (new Coord(0,1));
	orientationVector->applyAngle(angle);
	this->orientationVector = orientationVector;
	this->motionVector = new Coord(0,-id);
	this->motionAngle = 0;
	this->collisionHandler = collisionHandler;
	this->id = id;
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

std::vector<Segment*> Shape::getField(long time) {
	std::vector<Segment*> boundaries = drawBody(time, getPosition(time));
	return boundaries;
}

//generates segments that define the collision body about a point that is the center of mass
std::vector<Segment*> Shape::drawBody(long t, Coord* position) {
	std::vector<Segment*> body;
	//I am hardcoding this to be a square of sidelength 15 in the meantime
	Coord* stroke = position->clone();
	Coord* nextStroke = position->clone();
	nextStroke->add(-7.5,7.5);//top left corner 
	stroke->add(-7.5,-7.5);//bottom left corner
	Segment* leftEdge = new Segment(stroke,nextStroke, t, this->id);
	stroke->add(15,15);
	Segment* topEdge = new Segment(nextStroke, stroke, t, this->id);
	nextStroke->add(15,-15);
	Segment* rightEdge = new Segment(stroke, nextStroke, t, this->id);
	stroke->add(-15,-15);
	Segment* bottomEdge = new Segment(nextStroke, stroke, t, this->id);
	body.push_back(leftEdge);
	body.push_back(topEdge);
	body.push_back(rightEdge);
	body.push_back(bottomEdge);
	delete(stroke);
	delete(nextStroke);
	return body;
}
Coord* Shape::getPosition(long time) {
	long deltaT = this->currentTime - time;
	if (motionVector->equals(0,0)) return this->position;
	//pretend there is only linear constant motion
	Coord* newPosition = this->motionVector->clone();
	newPosition->multiply(deltaT);
	newPosition->add(this->position);
	return newPosition;
}

Coord* Shape::getMotionVector() {
	return this->motionVector;
}

char* Shape::ToString() {
	return " properties not implemented yet!\n";
}