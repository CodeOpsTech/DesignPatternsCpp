#include "Circle.h"
#include "Canvas.h"
#include "ShapeArchiver.h"

int main(int argc, const char** argv)
{
	Circle *circle = new Circle(10, 10, 20);
	std::cout << circle->toString() << std::endl;
	Canvas tempVar;
	circle->setCanvas(&tempVar);
	ShapeArchiver tempVar2;
	circle->setShapeArchiver(&tempVar2);
	circle->setRadius(50);
	std::cout << circle->toString() << std::endl;
    	return 0;
}
