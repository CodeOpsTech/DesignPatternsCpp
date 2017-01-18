#include "DecoratorMain.h"

int main(int argc, char **argv)
{
    	BorderDecorator tempVar(new TextView());
	VisualComponent *comp = new ScrollDecorator(&tempVar);
	comp->draw();
	return 0;
}
