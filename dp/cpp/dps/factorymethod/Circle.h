#ifndef CIRCLE
#define CIRCLE

#include "Shape.h"
#include <string>
#include <iostream>

class Circle : public Shape
{
private:
	int xPos = 0, yPos = 0;
	int radius = 0;
public:
	Circle(int x, int y, int r);
	virtual void draw() override;
	virtual void fillColor() override;
};

#endif	//#ifndef CIRCLE
