#include "Segment.h"

Segment::Segment(double x1, double y1, double x2, double y2, long t, int shapeID): pos1(x1, y1), pos2(x2, y2), time(t), owner(shapeID) {

}

Segment::Segment(Coord pos1, Coord pos2, long t, int shapeID): pos1(pos1), pos2(pos2), time(t), owner(shapeID) {

}

Segment::~Segment() {

}

void Segment::findCollisions(
	const Shape& shape,
	const vector<Segment>& paths,
	vector<PreCollision>& PreCollisions,
	vector<int>& collisions) const {

	for (const auto& seg : paths)
	{
		if (this->intersects(seg)) {
			if (std::find(collisions.begin(), collisions.end(), seg.time) == collisions.end()) {
				collisions.push_back(seg.time);
			}
		}
	}
	
}

bool Segment::intersects(const Segment& seg) const {
	if (seg.time != this->time || this->owner == seg.owner && seg.time != -1) return false;
	Coord p0 = this->pos1;
	Coord p1 = this->pos2;
	p1 -= p0;
	Coord p2 = seg.pos1;
	p2 -= p0;
	Coord p3 = seg.pos2;
	p3 -= p0;
	double result1 = p1.det(p2);
	double result2 = p1.det(p3);
	//printf("%f %f\n", result, result2);
	if ((result1 > 0 && result2 < 0) || (result1 <0 && result2 > 0)) return true;
	return false; 
}