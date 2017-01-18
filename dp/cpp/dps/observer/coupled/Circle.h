#ifndef CIRCLE
#define CIRCLE

#include <string>

class Point;
class ShapeArchiver;
class Canvas;

// Circle class "informs" (i.e., "notifies") Canvas and ShapeArchiver whenever it gets "changed"
// by calling the update method of these two classes  
class Circle
{
private:
	Point *center;
public:
	virtual ~Circle()
	{
		delete center;
		delete shapeArchiver;
		delete canvas;
	}

	virtual void setCenter(Point *center);
	virtual void setRadius(int radius);
private:
	ShapeArchiver *shapeArchiver;
public:
	virtual void setShapeArchiver(ShapeArchiver *shapeArchiver);
protected:
	Canvas *canvas;
public:
	virtual void setCanvas(Canvas *canvas);
private:
	int radius = 0;
public:
	Circle(int x, int y, int r);
	virtual std::string toString();
};

#endif	//#ifndef CIRCLE
