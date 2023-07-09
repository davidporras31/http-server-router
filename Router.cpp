#include "Router.h"

Router::Router(){
	this->defaultRoute = 0;
}
Router::~Router(){
	for (size_t i = 0; i < this->routes.size(); ++i)
	{
		delete this->routes.at(i);
	}
}

void Router::addRoute(Route * route){
	this->routes.push_back(route);
}
Route* Router::getRoute(size_t id)
{
	return this->routes.at(id);
}
Route* Router::getRoute(std::string name)
{
	size_t id = this->getRouteId(name);
	return (id != SIZE_MAX) ? this->getRoute(id) : NULL;
}
size_t Router::getRouteId(std::string name)
{
	size_t ret = SIZE_MAX;

	for (size_t i = 0; i < this->routes.size(); i++)
	{
		if (this->getRoute(i)->getName() == name)
		{
			ret = i;
			break;
		}
	}

	return ret;
}
void Router::remove(size_t id)
{
	this->routes.erase(this->routes.begin() + id);
}
void Router::remove(std::string name)
{
	size_t id = this->getRouteId(name);
	if(id != SIZE_MAX) 
		this->remove(id);
}
void Router::setDefaultRoute(std::string name){
	size_t id = this->getRouteId(name);
	this->defaultRoute = (id != SIZE_MAX) ? id : 0;
}

size_t Router::getDefaultRoute()
{
	return this->defaultRoute;
}

#define REQUEST(NETHODE)\
	bool routeNotFound = true;\
	if(this->routes.size() != 0)\
	{\
		for (size_t i = 0; i < this->routes.size(); ++i)\
		{\
			Route * tmp = this->routes.at(i);\
			if(tmp->getName().length()+1 >= path->length())\
			if(tmp->getName() == path->substr(1,tmp->getName().length())){\
				tmp->NETHODE(socket, path->substr(tmp->getName().length()), data);\
				routeNotFound = false;\
				break;\
			}\
		}\
		if(routeNotFound){\
			this->routes.at(this->defaultRoute)->NETHODE(socket, *path, data);\
		}\
	}\
	return routeNotFound;

bool Router::GET(sf::TcpSocket * socket, std::string* path, std::string* data){
	//REQUEST(GET)
	bool routeNotFound = true;
	if (this->routes.size() != 0)
	{
		for (size_t i = 0; i < this->routes.size(); ++i)
		{
			Route* tmp = this->routes.at(i);
			if (tmp->getName().length() + 1 <= path->length())
				if (tmp->getName() == path->substr(1, tmp->getName().length())) {
					tmp->GET(socket, path->substr(tmp->getName().length() + 1), data);
					routeNotFound = false;
					break;
				}
		}
	}
	return routeNotFound;
}
bool Router::HEAD(sf::TcpSocket * socket, std::string* path, std::string* data){
	REQUEST(HEAD)
}
bool Router::POST(sf::TcpSocket * socket, std::string* path, std::string* data){
	REQUEST(POST)
}
bool Router::OPTIONS(sf::TcpSocket * socket, std::string* path, std::string* data){
	REQUEST(OPTIONS)
}
bool Router::CONNECT(sf::TcpSocket * socket, std::string* path, std::string* data){
	REQUEST(CONNECT)
}
bool Router::TRACE(sf::TcpSocket * socket, std::string* path, std::string* data){
	REQUEST(TRACE)
}
bool Router::PUT(sf::TcpSocket * socket, std::string* path, std::string* data){
	REQUEST(PUT)
}
bool Router::PATCH(sf::TcpSocket * socket, std::string* path, std::string* data){
	REQUEST(PATCH)
}
bool Router::DELETE(sf::TcpSocket * socket, std::string* path, std::string* data){
	REQUEST(DELETE)
}