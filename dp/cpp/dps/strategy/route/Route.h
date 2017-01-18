#ifndef ROUTE
#define ROUTE

#include <string>
#include <vector>
#include <iostream>
#include <functional>

using Algorithm = std::function<std::string()>;

class Route
{
private:
	Algorithm algo = [&](void){ return std::string("Dijkstras algo"); };
public:
	std::string src, dst;
    	Route() { }

	Route(const std::string &src, const std::string &dst);
	virtual std::string getShortestPath();
	virtual void setAlgorithm(const Algorithm &algo);
};

#endif	//#ifndef ROUTE
