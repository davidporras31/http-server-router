#include "Router.h"

Router::Router(){
	this->defaultRoute = 0;
}
Router::~Router(){
	for (int i = 0; i < this->routes.size(); ++i)
	{
		delete this->routes.at(i);
	}
}

void Router::addRoute(Route * route){
	this->routes.push_back(route);
}
void Router::setDefaultRoute(std::string name){
	for (int i = 0; i < this->routes.size(); ++i)
	{
		if(this->routes.at(i)->getName() == name){
			this->defaultRoute = i;
			break;
		}
	}
}

#define REQUEST(NETHODE)\
	bool flipflop = true;\
	if(this->routes.size() != 0)\
	{\
		for (int i = 0; i < this->routes.size(); ++i)\
		{\
			Route * tmp = this->routes.at(i);\
			if(tmp->getName().length() >= path->length())\
			if(tmp->getName() == path->substr(0,tmp->getName().length())){\
				tmp->NETHODE(socket, path->substr(tmp->getName().length()), data);\
				flipflop = false;\
				break;\
			}\
		}\
		if(flipflop){\
			this->routes.at(this->defaultRoute)->setRedirected(true);\
			this->routes.at(this->defaultRoute)->NETHODE(socket, *path, data);\
			this->routes.at(this->defaultRoute)->setRedirected(false);\
		}\
	}

void Router::GET(win::SOCKET socket, std::string* path, std::string* data){
	REQUEST(GET)
}
void Router::HEAD(win::SOCKET socket, std::string* path, std::string* data){
	REQUEST(HEAD)
}
void Router::POST(win::SOCKET socket, std::string* path, std::string* data){
	REQUEST(POST)
}
void Router::OPTIONS(win::SOCKET socket, std::string* path, std::string* data){
	REQUEST(OPTIONS)
}
void Router::CONNECT(win::SOCKET socket, std::string* path, std::string* data){
	REQUEST(CONNECT)
}
void Router::TRACE(win::SOCKET socket, std::string* path, std::string* data){
	REQUEST(TRACE)
}
void Router::PUT(win::SOCKET socket, std::string* path, std::string* data){
	REQUEST(PUT)
}
void Router::PATCH(win::SOCKET socket, std::string* path, std::string* data){
	REQUEST(PATCH)
}
void Router::DELETE(win::SOCKET socket, std::string* path, std::string* data){
	REQUEST(DELETE)
}