#pragma once
#include <node.h>
#include <v8.h>
#include <iostream>
#include <math.h>
#include <memory>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include "Box2D/Box2D.h"
using std::vector;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
using std::cout;
using std::cerr;
using std::endl;

#define BOUNDARY_BLOCKING 0//bounce off edge, registers as collision
#define BOUNDARY_SLIDING 1//leave one side enter other
#define BOUNDARY_NONE 2//can leave map
