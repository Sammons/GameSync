#include "Segment.h"

Segment::Segment(double x1, double y1, double x2, double y2, long t, int shapeID) {
	this->pos1 = new Coord(x1, y1);
	this->pos2 = new Coord(x2, y2);
	this->time = t;
	this->owner = shapeID;
}

Segment::Segment(Coord* pos1, Coord* pos2, long t, int shapeID) {
	this->pos1 = pos1->clone();
	this->pos2 = pos2->clone();
	this->time = t;
	this->owner = shapeID;
}

Segment::~Segment() {

}

void Segment::findCollisions(Shape* shape,
	 std::vector<Segment*>* paths,
	 std::vector<PreCollision*>* PreCollisions,
	 std::vector<Collision*>* Collisions) {
	std::vector<int> collisions;
	for (unsigned int i = 0; i < paths->size(); ++i)
	{
		if (this->intersects((*paths)[i])) {
			if (!(std::find(collisions.begin(), collisions.end(), (*paths)[i]->owner) != collisions.end())) {
				collisions.push_back((*paths)[i]->owner);
			}
		}
	}
	if (collisions.size() > 0 ) printf("shape %d collides with ", this->owner);
	for (int i = 0; i < collisions.size(); ++i)
	{
		printf("%d ",collisions[i]);
	}
	if (collisions.size() > 0 ) printf("\n");
}

bool Segment::intersects(Segment* seg) {
	if (seg->time != this->time || this->owner == seg->owner && seg->time != -1) return false;
	Coord* p0 = this->pos1;
	Coord* p1 = this->pos2->clone();
	p1->subtract(p0);
	Coord* p2 = seg->pos1->clone();
	p2->subtract(p0);
	Coord* p3 = seg->pos2->clone();
	p3->subtract(p0);
	double result1 = p1->det(p2);
	double result2 = p1->det(p3);
	//printf("%f %f\n", result, result2);
	delete(p2);
	delete(p1);
	delete(p3);
	if ((result1 > 0 && result2 < 0) || (result1 <0 && result2 >0) || (result1 ==0 || result2==0)) return true;
	return false; 
}