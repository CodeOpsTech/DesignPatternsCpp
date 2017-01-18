#include "DisplayFriendlyCircle.h"
#include <iostream>

DisplayFriendlyCircle::DisplayFriendlyCircle(int x, int y, int r)
{
	xPos = x;
	yPos = y;
	radius = r;
	std::cout << std::string("DisplayFriendlyCircle constructor") << std::endl;
}

void DisplayFriendlyCircle::draw()
{
	std::cout << std::string("DisplayFriendlyCircle draw()") << std::endl;
	// draw() implementation
}
