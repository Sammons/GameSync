#include "commonheaders.h"
collision_system::collision_system() {
}
collision_system::~collision_system() {
}
owner* collision_system::addShape(shape* s) {
	int i;
	for (i =0; i < s->numSegments; i++) {
		partition* p = this->determinePartition(&(s->segments[i]));
		owner* o = p->addSegment(&(s->segments[i]));
		if (o != NULL) {
			delete(s);
			return o;
		}
	}
	return NULL;
}

partition* collision_system::determinePartition(segment* s) {
 	return NULL;
}