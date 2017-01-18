#include "Point.h"

Point::Point(int x, int y)
{
	xPos = x;
	yPos = y;
}

Point::~Point() { } 

std::string Point::toString()
{
	return std::string("(") + std::to_string(xPos) + std::string(",") + std::to_string(yPos) + std::string(")");
}
