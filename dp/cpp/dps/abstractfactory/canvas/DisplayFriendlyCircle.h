#pragma once

#include "DisplayFriendlyShape.h"
#include <string>
#include <iostream>

class DisplayFriendlyCircle : public DisplayFriendlyShape
{
private:
	int xPos, yPos;
	int radius;
public:
	DisplayFriendlyCircle(int x, int y, int r);
	virtual void draw();
};
