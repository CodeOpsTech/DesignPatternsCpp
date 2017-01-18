#ifndef SHAPEARCHIVER
#define SHAPEARCHIVER

#include <string>
#include <iostream>

class Circle;

class ShapeArchiver
{
public:
	virtual void update(Circle *circle);
};


#endif	//#ifndef SHAPEARCHIVER
