#include "Rectangle.h"

Rectangle::Rectangle(int length, int height)
{
	this->length = length;
	this->height = height;
	std::cout << std::string("Rectangle constructor") << std::endl;
}

void Rectangle::draw()
{
	std::cout << std::string("Rectangle draw()") << std::endl;
	// draw() implementation
}

void Rectangle::fillColor()
{
	// fillColor() implementation
}
