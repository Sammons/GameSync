#include "Scene.h"

Scene::Scene(double mapHeight, double mapWidth, int boundaryType, int predictionLength, v8::Local<v8::Function> endCallback)
	:time(0), mapHeight(mapHeight), mapWidth(mapWidth), boundaryType(boundaryType), predictionLength(predictionLength), EndCallback(endCallback) {

}

Scene::~Scene() {
	const unsigned argc = 0;
	v8::Local<v8::Value> argv[argc] = {};
	this->EndCallback->Call(v8::Context::GetCurrent()->Global(), argc, argv);

	// for (i = 0; i < Collisions.size(); ++i) {
	// 	delete(this->Collisions[i]);
	// 	this->Collisions[i] = NULL;
	// }
	// for (i = 0; i < PreCollisions.size(); ++i) {
	// 	delete(this->PreCollisions[i]);
	// 	this->PreCollisions[i] = NULL;
	// }
}

void Scene::tick(int times) {
	for (int i = 0; i < times; ++i)
	{
		time++;
		// unsigned int j;
		// for (j = 0; j < this->Collisions.size(); ++j) {
		// 	this->Collisions[i]->decrement();
		// }
		// for (j = 0; j < this->PreCollisions.size(); ++j) {
		// 	this->PreCollisions[i]->decrement();
		// }
	}
}

void Scene::addShape(Shape shape) {
	cout << "adding shape to scene" << endl;
	this->checkShape(shape);
	this->Shapes.push_back(shape);
	cout << "added shape with properties:" << shape.ToString() << endl;
};

void Scene::checkShape(Shape& shape) {
	cout << "performing initial check for collisions at position (" << shape.getPosition(time).x << ", " << shape.getPosition(time).y << ")\n";
	vector<Segment> currentField = shape.getField(time);
	for (const auto& seg : currentField)
	{
		printf("size: %lu p1: (%f, %f) p2: (%f, %f)\n", currentField.size(), seg.pos1.x, seg.pos2.y, seg.pos2.x, seg.pos2.y);
		seg.findCollisions(shape, PathFragments, PreCollisions, Collisions);
		this->PathFragments.push_back(seg);
	}
	this->shootRay(shape);	
}

//really its not a ray, its the predicted path
void Scene::shootRay(Shape& shape) {
	cout << "predicting trajectory for the next " << predictionLength << " ticks\n";
	//if (shape->getMotionVector()->equals(0,0))
	for (int i = 1; i <= this->predictionLength; ++i)
	{
		//get the segment that represents a shape's delta for this tick
		vector<Segment> Field = shape.getField(time + i);
		//find precollisions and collisions
		for (const auto& seg : Field) {
			seg.findCollisions(shape, PathFragments, PreCollisions, Collisions);

			//TODO: Here we end up creating copies of the segement.
			//The collections involved (shape.getField, PathFragments, and shape's PathSegments) will need to be changed to be of type shared_ptr<Segement>.
			//Or we can accept the memory overhead
			this->PathFragments.push_back(seg);
			shape.addToPath(seg); 
		}
	}
	cout << "Collision found for shape " << shape.id << " at times: ";
	
	for (int c : Collisions)
	{
		cout << c;
	}
	cout << endl;
}

long Scene::getTime() {
	return this->time;
}