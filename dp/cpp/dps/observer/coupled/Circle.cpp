#include "Circle.h"
#include "Point.h"
#include "ShapeArchiver.h"
#include "Canvas.h"

void Circle::setCenter(Point *center)
{
	this->center = center;
	canvas->update(this);
	shapeArchiver->update(this);
}

void Circle::setRadius(int radius)
{
	this->radius = radius;
	canvas->update(this);
	shapeArchiver->update(this);
}

void Circle::setShapeArchiver(ShapeArchiver *shapeArchiver)
{
	this->shapeArchiver = shapeArchiver;
}

void Circle::setCanvas(Canvas *canvas)
{
	this->canvas = canvas;
}

Circle::Circle(int x, int y, int r)
{
	center = new Point(x, y);
			   radius = r;
}

std::string Circle::toString()
{
	return std::string("center = ") + center->toString() + std::string(" and radius = ") + std::to_string(radius);
}
