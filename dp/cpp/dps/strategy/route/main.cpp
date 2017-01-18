#include "Route.h"

int main(int argc, char **argv)
{
	Route *route = new Route("yeshwantpur", "PES");
	std::cout << route->getShortestPath() << std::endl;
	
    	route->setAlgorithm([&] ()
	{
		return "Ganesh's algo";
	});
	std::cout << route->getShortestPath() << std::endl;
    
    	return 0;
}
