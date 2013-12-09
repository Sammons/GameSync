#pragma once
#include "commonheaders.h"
class owner;
class segment;
class partition
{
public:
	partition(int min_x, int min_y, int max_x, int max_y);
	~partition();
	owner* moveSegment(segment* s);
	owner* addSegment(segment* s);
	void removeSegment(int ownerID, int number);
};