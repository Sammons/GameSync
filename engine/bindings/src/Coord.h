#include "common.h"
class Coord
{
public:
	Coord(double x, double y);
	~Coord();
	void applyAngle(double angle);
	void add(double x, double y);
	void add(Coord* pos);
	void subtract(Coord* pos);
	bool equals(double x, double y);
	bool equals(Coord* pos);
	void multiply(double x);
	void multiply(double x, double y);
	void multiply(Coord* pos);
	double det(Coord* pos);
	Coord* clone();
	/* data */
	double x;
	double y;
};