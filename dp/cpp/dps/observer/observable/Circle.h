#ifndef CIRCLE
#define CIRCLE

#include <string>
#include "Observer.h"

class Point;

class Circle : public Observable
{
private:
	Point *center;
public:
	virtual ~Circle()
	{
		delete center;
	}

	virtual void setCenter(Point *center);
	virtual void setRadius(int radius);
private:
	int radius = 0;
public:
	Circle(int x, int y, int r);
	virtual std::string toString();
};


#endif	//#ifndef CIRCLE
