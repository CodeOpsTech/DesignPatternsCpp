#include "Circle.h"
#include "Point.h"

void Circle::setCenter(Point *center)
{
	this->center = center;
	notifyObservers(nullptr);
}

void Circle::setRadius(int radius)
{
	this->radius = radius;
	notifyObservers(nullptr);
}

Circle::Circle(int x, int y, int r)
{
	center = new Point(x, y);
    	radius = r;
}

std::string Circle::toString()
{
	return std::string("center = ") + center->toString() + std::string(" and radius = ") + std::to_string(radius);
}
