#pragma once

#include "common.h"
#include "Coord.h"

class Segment;
class Shape
{
public:
	Shape(double x, double y, double angle, long time, int id, v8::Local<v8::Function> collisionHandler);
	~Shape();
	void addSegment(Segment segment);
	void addToPath(Segment segment);
	vector<Segment> getField(long time) const;
	void handleCollision(const std::string &type); //wrapper for callback
	Coord getMotionVector();
	std::string ToString();
	Coord getPosition(long time) const;
	int id;
private:
	vector<Segment> drawBody(long time) const;
	vector<Segment> drawSquare(Coord center, long time, int sideLength) const;
	
	v8::Local<v8::Function> collisionHandler;

	vector<Segment> Segments;
	vector<Segment> PathSegments;
	Coord position;
	double orientationAngle; //theta for relative angle to 0,1 orientationVector
	long currentTime;
	Coord orientationVector; //unit vector for where they are pointed
	Coord motionVector;
	double motionAngle;


};