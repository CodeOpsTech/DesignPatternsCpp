#pragma once

#include <string>

class Shape;

class ShapeFactory
{
 public:
	 virtual  Shape *getShape(const std::string &sourceType) = 0;
};
