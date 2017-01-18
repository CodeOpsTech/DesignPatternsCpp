#pragma once

#include "PrinterFriendlyShape.h"
#include <string>
#include <iostream>

class PrinterFriendlyRectangle : public PrinterFriendlyShape
{
public:
	PrinterFriendlyRectangle(int length, int height);
private:
	int length, height;
public:
	virtual void draw();
};
