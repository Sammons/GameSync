#pragma once
#include <node.h>
#include <v8.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#define BOUNDARY_BLOCKING 0//bounce off edge, registers as collision
#define BOUNDARY_SLIDING 1//leave one side enter other
#define BOUNDARY_NONE 2//can leave map
using namespace v8;