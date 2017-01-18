#include "Canvas.h"
#include "Shape.h"
#include "ShapeFactory.h"
#include "PrinterFriendlyFactory.h"
#include "DisplayFriendlyFactory.h"

void Canvas::addNewShape(const std::string &shapeType, const std::string &factoryType)
{
	ShapeFactory *factory = 0;
	if (factoryType == "PrinterFriendly")
	{
		factory = new PrinterFriendlyFactory();
    	}
	else if (factoryType == "DisplayFriendly")
        {
		factory = new DisplayFriendlyFactory();
	}
	Shape *shape = factory->getShape(shapeType);
	shapeList.push_back(shape);
}

void Canvas::redraw()
{
	std::vector<Shape*>::const_iterator itr = shapeList.begin();
	while (itr != shapeList.end())
	{
		Shape *shape = *itr;
		shape->draw();
		itr++;
	}
}
