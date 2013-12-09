#include "dumb_collision.h"
dumb_collision::dumb_collision() {
	printf("%s\n", "Using stupid collision system");
}
dumb_collision::~dumb_collision() {
	printf("%s\n", "Cleaning up stupid collision system");
}

int dumb_collision::move_segment(double x, double y, int parent, int number) {
	if (x < 0 || x > mapWidth-1) return 0;//zero is wall
	if (y < 0 || y > mapHeight-1) return 0;
	return -1;
}
