#include "RouteAlgos.h"

std::string JohnsonsAlgo::findPath()
{
	return "Johnsons";
}

std::string DijkstrasAlgo::findPath()
{
	return "Dijkstras";
}

std::string BellmanFordsAlgo::findPath()
{
	return "Bellman Ford's";
}

Route::Route(const std::string &src, const std::string &dst)
{
	this->src = src;
	this->dst = dst;
}

std::string Route::getShortestPath()
{
	return algo->findPath();
}

ShortestPathAlgo *Route::getAlgorithm()
{
	return this->algo;
}

void Route::setAlgorithm(ShortestPathAlgo *algo)
{
	this->algo = algo;
}
