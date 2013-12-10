#include "common.h"
class Coord;
class Shape;
class PreCollision;
class Collision;
class Segment
{
public:
	Segment(double x1, double y1, double x2, double y2, long t, int shapeID);
	Segment(Coord* pos1, Coord* pos2, long t, int shapeID);
	~Segment();
	void findCollisions(Shape* shape,
	 std::vector<Segment*>* paths,
	 std::vector<PreCollision*>* PreCollisions,
	 std::vector<int>* Collisions);
	Coord* pos1;
	Coord* pos2;
	long time;
private:
	bool intersects(Segment* seg);
	int owner;
	//i intentionally hardcoded only two points because I don't want to try to do segments that bend or turn



	/* data */
};