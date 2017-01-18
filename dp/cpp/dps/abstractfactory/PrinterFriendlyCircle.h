#pragma once

#include "PrinterFriendlyShape.h"
#include <string>
#include <iostream>

class PrinterFriendlyCircle : public PrinterFriendlyShape
{
private:
	int xPos, yPos;
	int radius;
public:
	PrinterFriendlyCircle(int x, int y, int r);
	virtual void draw();
};
