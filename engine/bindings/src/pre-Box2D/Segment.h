#pragma once

#include "common.h"
#include "Coord.h"
#include "PreCollision.h"
#include "Collision.h"

class Shape;
class Segment
{
public:
	Segment(double x1, double y1, double x2, double y2, long t, int shapeID);
	Segment(Coord pos1, Coord pos2, long t, int shapeID);
	~Segment();
	void findCollisions(const Shape& shape,
		const vector<Segment>& paths,
		vector<PreCollision>& PreCollisions,
		vector<int>& Collisions) const;
	
	/* data */
	Coord pos1;
	Coord pos2;
	long time;
private:
	bool intersects(const Segment& seg) const;
	int owner;
	//i intentionally hardcoded only two points because I don't want to try to do segments that bend or turn



};