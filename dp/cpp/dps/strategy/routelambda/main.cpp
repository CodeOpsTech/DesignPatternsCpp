#include "RouteAlgosWithLambdas.h"

int main(int argc, char **argv)
{
	Route *route = new Route("Guindy", "Chennai Central");
	std::cout << route->getShortestPath() << std::endl;
	route->setAlgorithm(ShortestPathAlgos::johnsonsAlgo);
	std::cout << route->getShortestPath() << std::endl;
}
