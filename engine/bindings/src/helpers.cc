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

	bool assert_argument_count(const Arguments& args, int count) {
		return (args.Length() == count);
	}

}