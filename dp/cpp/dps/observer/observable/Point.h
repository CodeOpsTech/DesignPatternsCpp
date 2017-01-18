#ifndef POINT
#define POINT

#include <string>

class Point
{
private:
	int xPos = 0;
	int yPos = 0;
public:
	Point(int x, int y);
	virtual std::string toString();
};

#endif	//#ifndef POINT
