#ifndef ROUTER
#define ROUTER

#include "Route.h"
#include <SFML/Network/TcpSocket.hpp>
#include <vector>
#include <string> 

class Router
{
public:
	Router();
	~Router();

	void addRoute(Route * route);
	Route* getRoute(size_t id);
	Route* getRoute(std::string name);
	size_t getRouteId(std::string name);
	void remove(size_t id);
	void remove(std::string name);
	void setDefaultRoute(std::string name);
	size_t getDefaultRoute();

	bool GET(sf::TcpSocket * socket, std::string* path, std::string* data);
	bool HEAD(sf::TcpSocket * socket, std::string* path, std::string* data);
	bool POST(sf::TcpSocket * socket, std::string* path, std::string* data);
	bool OPTIONS(sf::TcpSocket * socket, std::string* path, std::string* data);
	bool CONNECT(sf::TcpSocket * socket, std::string* path, std::string* data);
	bool TRACE(sf::TcpSocket * socket, std::string* path, std::string* data);
	bool PUT(sf::TcpSocket * socket, std::string* path, std::string* data);
	bool PATCH(sf::TcpSocket * socket, std::string* path, std::string* data);
	bool DELETE(sf::TcpSocket * socket, std::string* path, std::string* data);
private:
	std::vector<Route *> routes;
	size_t defaultRoute;
};


#endif