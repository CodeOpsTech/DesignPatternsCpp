#include "Circle.h"

Circle::Circle(int x, int y, int r)
{
	xPos = x;
	yPos = y;
	radius = r;
	std::cout << std::string("Circle constructor") << std::endl;
}

void Circle::draw()
{
	std::cout << std::string("Circle draw()") << std::endl;
	// draw() implementation
}

void Circle::fillColor()
{
	// fillColor() implementation
}
