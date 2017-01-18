#include "RouteAlgosWithLambdas.h"

const std::function<std::string()> ShortestPathAlgos::dijkstrasAlgo = [&] ()
{
		return "Dijkstra's";
};
const std::function<std::string()> ShortestPathAlgos::bellmanFordsAlgo = [&] ()
{
		return "Bellman Ford's";
};
const std::function<std::string()> ShortestPathAlgos::johnsonsAlgo = [&] ()
{
		return "Johnson's";
};

Route::Route(const std::string &src, const std::string &dst)
{
	this->src = src;
	this->dst = dst;
}

std::string Route::getShortestPath()
{
	return algo();
}

void Route::setAlgorithm(const std::function<std::string()> &algo)
{
	this->algo = algo;
}
