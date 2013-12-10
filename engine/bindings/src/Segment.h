#include "common.h"
class Shape;
class PreCollision;
class Collision;

class Segment
{
public:
	Segment();
	~Segment();
	void findCollisions(Shape* shape,
	 std::vector<Segment*>* pathFragments,
	 std::vector<PreCollision*>* PreCollisions,
	 std::vector<Collision*>* Collisions);
	/* data */
};