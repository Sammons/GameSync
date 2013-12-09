
class dumb_collision
{
public:
	 dumb_collision();
	 ~dumb_collision();
	int add_segment(double x, double y, int parent, int number);//i.e. parent 1, segment 2
	int update_segment(double x, double y, int parent, int number);
	void remove_segment(int parent, int number);
private:

};