#include "commonheaders.h"
#include "config.h"
#include "collision_system.h"
collision_system::collision_system() {
	this->numPartitions = 
		ceil((mapWidth/partitionWidth))
		*
		ceil((mapHeight/partitionHeight));
	this->partitions = (partition**)calloc(this->numPartitions,sizeof(partition*));
	int i;
	int min_x = 0;
	int min_y = 0;
	int max_x = partitionWidth;
	int max_y = partitionHeight;
	int partitionsWide = ceil(mapWidth/partitionWidth);
	for (i = 0; i < this->numPartitions; ++i){
		this->partitions[i] = new partition(min_x,min_y,max_x,max_y);
		if (i%partitionsWide != 0) {
			min_x = max_x;
			min_y = max_y;
		} else {
			max_x = max_x + partitionWidth;
			max_y = max_y + partitionHeight;
		}
	}
	if (this->partitions == NULL) {
		fprintf(stderr, "%s\n", "While instantiating the partitions the system refused");
	}
}
collision_system::~collision_system() {
	for (int i = 0; i < this->numPartitions; ++i) {
		if (this->partitions[i] != NULL) {
			delete(this->partitions[i]);
		}
	}
	free(this->partitions);
	this->partitions = NULL;
}
owner* collision_system::addShape(shape* s) {
	//want to make it so multiple things can collide with it at once
	int i;
	for (i =0; i < s->numSegments; i++) {
		partition* p = this->determinePartition(&(s->segments[i]));
		owner* o = p->addSegment(&(s->segments[i]));
	}
	return NULL;
}

partition* collision_system::determinePartition(segment* s) {

 	return NULL;
}