
class partition
{
public:
	partition();
	~partition();

	owner* moveSegment(segment* s);
	owner* addSegment(segment* s);
	void removeSegment(int ownerID, int number);
};