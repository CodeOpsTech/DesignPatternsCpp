#include "DecoratorMain.h"

VisualComponent::~VisualComponent() { } 

void TextView::draw()
{
	std::cout << std::string("Calling TextView.draw()") << std::endl;
}

Decorator::Decorator(VisualComponent *component)
{
	this->component = component;
}

void Decorator::draw()
{
	if (component != nullptr)
	{
		component->draw();
	}
}

ScrollDecorator::ScrollDecorator(VisualComponent *component) : Decorator(component)
{
}

void ScrollDecorator::draw()
{
	Decorator::draw();
	std::cout << std::string("Calling ScrollDecorator.draw()") << std::endl;
}

BorderDecorator::BorderDecorator(VisualComponent *component) : Decorator(component)
{
}

void BorderDecorator::draw()
{
	Decorator::draw();
	std::cout << std::string("Calling BorderDecorator.draw()") << std::endl;
}

