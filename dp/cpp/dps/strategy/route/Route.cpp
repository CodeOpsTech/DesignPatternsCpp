#include "Route.h"

Route::Route(const std::string &src, const std::string &dst)
{
	this->src = src;
	this->dst = dst;
}

std::string Route::getShortestPath()
{
	return algo();
}

void Route::setAlgorithm(const Algorithm &algo)
{
	this->algo = algo;
}

