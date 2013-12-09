#include "commonheaders.h"
#include "owner.h"
#include "segment.h"
#include "partition.h"
#include "shape.h"
class collision_system
{
public:
	collision_system();
	~collision_system();
	owner* addShape(shape* s);
	owner* updateShape(shape* s);
private:
	partition* determinePartition(segment* s);
	partition** partitions;
	int numPartitions;
	shape* shapes;

};