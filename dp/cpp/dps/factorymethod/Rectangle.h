#ifndef RECTANGLE
#define RECTANGLE

#include "Shape.h"
#include <string>
#include <iostream>

class Rectangle : public Shape
{
public:
	Rectangle(int length, int height);
private:
	int length = 0, height = 0;
public:
	virtual void draw() override;
	virtual void fillColor() override;
};

#endif	//#ifndef RECTANGLE
