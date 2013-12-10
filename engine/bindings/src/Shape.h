#include "common.h"
#include "Coord.cpp"
class Segment;
class Shape
{
public:
	Shape(double x, double y, double angle,long time, Local<Function> collisionHandler);
	~Shape();
	void addSegment(Segment* segment);
	void addToPath(Segment* segment);
	Segment* getRaySegment(long timeFrame);
	void handleCollision(const char* type);
private:
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