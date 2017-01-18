#ifndef ROUTEALGOSWITHLAMBDAS
#define ROUTEALGOSWITHLAMBDAS

#include <string>
#include <vector>
#include <iostream>
#include <functional>

class Supplier;

class ShortestPathAlgos
{
public:
	static const std::function<std::string()> dijkstrasAlgo;
	static const std::function<std::string()> bellmanFordsAlgo;
	static const std::function<std::string()> johnsonsAlgo;
};

class Route
{
public:
	std::string src, dst;
	Route(const std::string &src, const std::string &dst);
	std::function<std::string()> algo = ShortestPathAlgos::dijkstrasAlgo;
	virtual std::string getShortestPath();
	virtual void setAlgorithm(const std::function<std::string()> &algo);
	static void main(std::vector<std::string> &args);
};


#endif	//#ifndef ROUTEALGOSWITHLAMBDAS
