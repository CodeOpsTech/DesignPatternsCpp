#ifndef SHAPEARCHIVER
#define SHAPEARCHIVER

#include <string>
#include <iostream>
#include "Observer.h"

class ShapeArchiver : public Observer
{
public:
	virtual void update(Observable *arg0, void *arg1) override;
};


#endif	//#ifndef SHAPEARCHIVER
