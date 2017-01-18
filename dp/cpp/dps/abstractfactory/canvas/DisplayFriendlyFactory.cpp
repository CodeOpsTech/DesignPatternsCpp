#include "DisplayFriendlyFactory.h"
#include "Shape.h"
#include "DisplayFriendlyCircle.h"
#include "DisplayFriendlyRectangle.h"

Shape *DisplayFriendlyFactory::getShape(const std::string &sourceType)
{
	if (sourceType == "Circle")
		return new DisplayFriendlyCircle(10, 10, 20);
	else if (sourceType == "Rectangle")
		return new DisplayFriendlyRectangle(10, 20);
	return 0;
}
