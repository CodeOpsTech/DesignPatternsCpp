#ifndef DECORATORMAIN
#define DECORATORMAIN

#include <string>
#include <vector>
#include <iostream>

class VisualComponent
{
public:
	virtual void draw() = 0;
	virtual ~VisualComponent(); 
};

class TextView : public VisualComponent
{
public:
	virtual void draw() override;
};

class Decorator : public VisualComponent
{
private:
	VisualComponent *component = nullptr;
public:
	virtual ~Decorator()
	{
		delete component;
	}

	Decorator(VisualComponent *component);
	virtual void draw() override;
};

class ScrollDecorator : public Decorator
{
public:
	ScrollDecorator(VisualComponent *component);
	virtual void draw() override;
};

class BorderDecorator : public Decorator
{
public:
	BorderDecorator(VisualComponent *component);
	virtual void draw() override;
};

#endif	//#ifndef DECORATORMAIN
