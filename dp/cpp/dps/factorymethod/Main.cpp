#include "Canvas.h"

int main(int argc, char **argv)
{
	Canvas *canvas = new Canvas();
	canvas->addNewShape("Circle");
	canvas->addNewShape("Rectangle");
	canvas->redraw();
}
