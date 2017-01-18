#ifndef CANVAS
#define CANVAS

#include <string>
#include <vector>

class Shape;

class Canvas
{
private:
	std::vector<Shape*> shapeList;
public:
	virtual void addNewShape(const std::string &shapeType);
	virtual void redraw();
};


#endif	//#ifndef CANVAS
