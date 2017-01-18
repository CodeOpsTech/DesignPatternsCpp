#ifndef CANVAS
#define CANVAS

#include <string>
#include <iostream>

class Circle;

class Canvas
{
public:
	virtual void update(Circle *circle);
};

#endif	//#ifndef CANVAS
