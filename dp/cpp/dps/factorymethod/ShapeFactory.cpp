#include "ShapeFactory.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

Shape *ShapeFactory::getShape(const std::string &sourceType)
{
   
   if(sourceType == "Circle")
	   return new Circle(10, 10, 20);
   else if(sourceType == "Rectangle")
	   return new Rectangle(10, 20);
   else
        return nullptr;
}
