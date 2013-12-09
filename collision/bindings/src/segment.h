class segment
{
public:
	segment();
	~segment();
	owner* intersects(segment* s);
	void move(double x, double y);
	/* data */
};