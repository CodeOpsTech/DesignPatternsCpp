#include "DisplayFriendlyRectangle.h"

DisplayFriendlyRectangle::DisplayFriendlyRectangle(int length, int height): length(0), height(0)
{
	this->length = length;
	this->height = height;
	std::cout << std::string("DisplayFriendlyRectangle constructor") << std::endl;
}

void DisplayFriendlyRectangle::draw()
{
	std::cout << std::string("DisplayFriendlyRectangle draw()") << std::endl;
	// draw() implementation
}
