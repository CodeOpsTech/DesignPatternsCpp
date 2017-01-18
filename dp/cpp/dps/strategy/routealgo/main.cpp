#include "RouteAlgos.h"

int main(int argc, char **argv)
{
	Route *route = new Route("Guindy", "Chennai Central");
	std::cout << route->getShortestPath() << std::endl;
    
	BellmanFordsAlgo tempVar;
	route->setAlgorithm(&tempVar);
	std::cout << route->getShortestPath() << std::endl;
    
    	return 0;
}
