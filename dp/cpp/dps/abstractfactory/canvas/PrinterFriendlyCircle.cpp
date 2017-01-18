#include "PrinterFriendlyCircle.h"

PrinterFriendlyCircle::PrinterFriendlyCircle(int x, int y, int r)
{
	xPos = x;
	yPos = y;
	radius = r;
	std::cout << std::string("PrinterFriendlyCircle constructor") << std::endl;
}

void PrinterFriendlyCircle::draw()
{
	std::cout << std::string("PrinterFriendlyCircle draw()") << std::endl;
}
