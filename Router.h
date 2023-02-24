#ifndef ROUTER
#define ROUTER

#include "Route.h"
#include <vector>
#include <string> 

class Router
{
public:
	Router();
	~Router();

	void addRoute(Route * route);
	void setDefaultRoute(std::string name);

	void GET(win::SOCKET socket, std::string* path, std::string* data);
	void HEAD(win::SOCKET socket, std::string* path, std::string* data);
	void POST(win::SOCKET socket, std::string* path, std::string* data);
	void OPTIONS(win::SOCKET socket, std::string* path, std::string* data);
	void CONNECT(win::SOCKET socket, std::string* path, std::string* data);
	void TRACE(win::SOCKET socket, std::string* path, std::string* data);
	void PUT(win::SOCKET socket, std::string* path, std::string* data);
	void PATCH(win::SOCKET socket, std::string* path, std::string* data);
	void DELETE(win::SOCKET socket, std::string* path, std::string* data);
private:
	std::vector<Route *> routes;
	size_t defaultRoute;
};


#endif