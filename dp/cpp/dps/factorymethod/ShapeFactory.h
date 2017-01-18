#ifndef SHAPEFACTORY
#define SHAPEFACTORY

#include <string>

class Shape;

class ShapeFactory
{
 public:
	 static Shape *getShape(const std::string &sourceType);
};

#endif	//#ifndef SHAPEFACTORY
