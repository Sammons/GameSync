#include "common.h"
class Coord;
class Segment;
class Shape
{
public:
	Shape(double x, double y, double angle,long time,int id, Local<Function> collisionHandler);
	~Shape();
	void addSegment(Segment* segment);
	void addToPath(Segment* segment);
	std::vector<Segment*> getField(long time);
	void handleCollision(const char* type);//wrapper for callback
	Coord* getMotionVector();
	char* ToString();
	Coord* getPosition(long time);
	int id;
private:
	std::vector<Segment*> drawBody(long time, Coord* position);
	Local<Function> collisionHandler;

	std::vector<Segment*> Segments;
	std::vector<Segment*> PathSegments;
	long currentTime;
	Coord* position;
	double orientationAngle;//theta for relative angle to 0,1 orientationVector
	Coord* orientationVector;//unit vector for where they are pointed
	Coord* motionVector;
	double motionAngle;


};