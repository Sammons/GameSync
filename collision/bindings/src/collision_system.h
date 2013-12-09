
class collision_system
{
public:
	shape* shapes;
	collision_system();
	~collision_system();
	owner* addShape(shape* s);
	owner* updateShape(shape* s);
private:
	partition* determinePartition(segment* s);
};