#include "PrinterFriendlyRectangle.h"

PrinterFriendlyRectangle::PrinterFriendlyRectangle(int length, int height)
{
	this->length = length;
	this->height = height;
	std::cout << std::string("PrinterFriendlyRectangle constructor") << std::endl;
}

void PrinterFriendlyRectangle::draw()
{
	std::cout << std::string("PrinterFriendlyRectangle draw()") << std::endl;
}
