#pragma once

#include "ShapeFactory.h"
#include <string>

class Shape;

class PrinterFriendlyFactory : public ShapeFactory
{
public:
	virtual Shape *getShape(const std::string &sourceType);
};
