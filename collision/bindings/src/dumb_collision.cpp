#include <stdio.h>
#include "dumb_collision.h"

dumb_collision::dumb_collision() {
	printf("%s\n", "Using stupid collision system");
}
dumb_collision::~dumb_collision() {
	printf("%s\n", "Cleaning up stupid collision system");

}
