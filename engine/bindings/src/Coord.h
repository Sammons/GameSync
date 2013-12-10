#include "common.h"
class Coord
{
public:
	Coord(double x, double y);
	~Coord();
	void applyAngle(double angle);
	/* data */
private:
	double x;
	double y;
};