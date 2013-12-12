#pragma once

#include "common.h"
#include "Collision.h"
#include "PreCollision.h"
#include "Coord.cpp"
#include "Segment.cpp"
#include "Shape.cpp"

class Scene
{
public:
	Scene(double mapHeight, double mapWidth, int boundaryType, int predictionLength, v8::Local<v8::Function> endCallback);
	~Scene();

	//add shape
	void addShape(Shape shape);
	void removeShape(int id, v8::Local<v8::Function> callback);
	void getShape(int id);
	//void updateShape(int id, const std::string prop, double value1, double value2, Local<Function> callback);
	void tick(int times);
	long getTime();

private:
	void checkShape(Shape& shape);
	void shootRay(Shape& shape);

	//physical properties of the world
	long mapWidth;
	long mapHeight;
	int predictionLength;
	int boundaryType;
	unsigned long time;

	//would be cool if a callback could be fired when everything ends
	v8::Local<v8::Function> EndCallback;

	//things the world keeps track of
	vector<Segment> PathFragments;
	vector<Shape> Shapes;
	vector<PreCollision> PreCollisions;
	vector<int> Collisions;
};