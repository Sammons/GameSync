#include "project.h"

namespace boxManagers {
	Handle<Value> Tick(const Arguments& args) {
		HandleScope scope;
		float32 timeStep = 1.0f / 60.0f;
		int32 velocityIterations = 6;
		int32 positionIterations = 2;
		globals::world->Step(timeStep, velocityIterations, positionIterations);
		return True();
	}
	Handle<Value> Update(const Arguments& args) {
		HandleScope scope;
		globals::world->UpdateBodies();
		return scope.Close(Undefined());
	}
}