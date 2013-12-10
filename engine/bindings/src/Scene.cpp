#include "Scene.h"

Scene::Scene(double mapHeight, double mapWidth, int boundaryType,int predictionLength, Local<Function> endCallback) {
	this->EndCallback = endCallback;
	this->mapWidth = mapWidth;
	this->mapHeight= mapHeight;
	this->boundaryType = boundaryType;
	this->time = 0;
	this->predictionLength = predictionLength;
}

Scene::~Scene() {
	const unsigned argc = 0;
	Local<Value> argv[argc] = {};
	this->EndCallback->Call(Context::GetCurrent()->Global(),argc,argv);
	unsigned int i = 0;
	for (i = 0; i < this->PathFragments.size(); ++i)
	{
		delete(this->PathFragments[i]);
		this->PathFragments[i] = NULL;
	}
	for (i = 0; i < Shapes.size(); ++i)
	{
		delete(this->Shapes[i]);
		this->Shapes[i] = NULL;
	}
	for (i = 0; i < Collisions.size(); ++i) {
		delete(this->Collisions[i]);
		this->Collisions[i] = NULL;
	}
	for (i = 0; i < PreCollisions.size(); ++i) {
		delete(this->PreCollisions[i]);
		this->PreCollisions[i] = NULL;
	}
}

void Scene::tick(int times) {
	for (int i = 0; i < times; ++i)
	{
		this->time++;
		unsigned int j;
		for (j = 0; j < this->Collisions.size(); ++j) {
			this->Collisions[i]->decrement();
		}
		for (j = 0; j < this->PreCollisions.size(); ++j) {
			this->PreCollisions[i]->decrement();
		}
	}
}

void Scene::addShape(Shape* shape) {
	printf("%s\n", "adding shape to scene");
	this->checkShape(shape);
	this->Shapes.push_back(shape);
};

void Scene::checkShape(Shape* shape) {
	Segment* currentFragment = shape->getRaySegment(time);
	currentFragment->findCollisions(shape, &(this->PathFragments), &(this->PreCollisions), &(this->Collisions));
	this->PathFragments.push_back(currentFragment);
	this->shootRay(shape);	
}

//really its not a ray, its the predicted path
void Scene::shootRay(Shape* shape) {
	for (int i = 1; i <= this->predictionLength; ++i)
	{
		//get the segment that represents a shape's delta for this tick
		Segment* pathFragment = shape->getRaySegment(this->time+i);
		//find precollisions and collisions
		pathFragment->findCollisions(shape, &(this->PathFragments), &(this->PreCollisions), &(this->Collisions));
		this->PathFragments.push_back(pathFragment);
		shape->addToPath(pathFragment);
	}
}

long Scene::getTime() {
	return this->time;
}