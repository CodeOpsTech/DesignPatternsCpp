#ifndef CANVAS
#define CANVAS

#include <string>
#include <iostream>
#include "Observer.h"

class Canvas : public Observer
{
public:
	virtual void update(Observable *arg0, void *arg1) override;
};

#endif	//#ifndef CANVAS
