#ifndef ROUTEALGOS
#define ROUTEALGOS

#include <string>
#include <vector>
#include <iostream>

class ShortestPathAlgo
{
public:
	virtual std::string findPath() = 0;
};

class JohnsonsAlgo : public ShortestPathAlgo
{
public:
	virtual std::string findPath();
};

class DijkstrasAlgo : public ShortestPathAlgo
{
public:
	virtual std::string findPath();
};

class BellmanFordsAlgo : public ShortestPathAlgo
{
public:
	virtual std::string findPath();
};

class Route
{
public:
	std::string src, dst;
	Route(const std::string &src, const std::string &dst);
	ShortestPathAlgo *algo = new DijkstrasAlgo();
	virtual std::string getShortestPath();
	virtual ShortestPathAlgo *getAlgorithm();
	virtual void setAlgorithm(ShortestPathAlgo *algo);
};


#endif	//#ifndef ROUTEALGOS
