#include "project.h"

using namespace std;
using namespace v8;
//these functions are relatively generic helpers

namespace helpers {

	void sleep(unsigned int mseconds)
	{
	    clock_t goal = mseconds + clock();
	    while (goal > clock());
	}


}