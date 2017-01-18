#include <string>
#include <vector>

class Shape;

class Canvas
{
private:
	std::vector<Shape*> shapeList;
public:
	virtual void addNewShape(const std::string &shapeType, const std::string &factoryType);
	virtual void redraw();
};
