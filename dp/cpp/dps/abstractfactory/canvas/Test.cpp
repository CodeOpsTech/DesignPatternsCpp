#include "Test.h"
#include "Canvas.h"

void Test::main()
{
	Canvas *canvas = new Canvas();
	canvas->addNewShape("Circle", "DisplayFriendly");
	canvas->addNewShape("Rectangle", "DisplayFriendly");
	canvas->redraw();
}

int main(int argc, const char** argv)
{
    Test test1;
    test1.main();
}
