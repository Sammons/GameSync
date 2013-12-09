#pragma once
#include "commonheaders.h"
class owner;
class partition;
class segment
{
public:
	segment();
	~segment();
	owner* move(double x, double y);
	/* data */
private:
	int numPartitions;
	partition* partitions;
};