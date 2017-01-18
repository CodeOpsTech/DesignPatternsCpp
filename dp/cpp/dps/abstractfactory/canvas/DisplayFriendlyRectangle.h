#pragma once

#include "DisplayFriendlyShape.h"
#include <string>
#include <iostream>

class DisplayFriendlyRectangle : public DisplayFriendlyShape
{
public:
	DisplayFriendlyRectangle(int length, int height);
private:
	int length, height;
public:
	virtual void draw();
};
