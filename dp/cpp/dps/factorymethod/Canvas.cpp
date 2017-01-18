#include "Canvas.h"
#include "Shape.h"
#include "ShapeFactory.h"

void Canvas::addNewShape(const std::string &shapeType)
{
	Shape *shape = ShapeFactory::getShape(shapeType);
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
