#include "PrinterFriendlyFactory.h"
#include "Shape.h"
#include "PrinterFriendlyCircle.h"
#include "PrinterFriendlyRectangle.h"

Shape *PrinterFriendlyFactory::getShape(const std::string &sourceType)
{
	if (sourceType == "Circle")
		return new PrinterFriendlyCircle(10, 10, 20);
	else if (sourceType == "Rectangle")
		return new PrinterFriendlyRectangle(10, 20);
	else
        	return 0;
}
