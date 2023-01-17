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
	this->routes.pushback(route);
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
	for (int i = 0; i < this->routes.size(); ++i)\
	{\
		Route * tmp = this->routes.at(i);\
		if(tmp->getName() == path.cstr(0,tmp->getName().lenght())){\
			tmp->GET(socket,path->cstr(tmp->getName().lenght(),path->lenght()),data);\
			this->flipflop = flase;\
			break;\
		}\
	}\
	if(flipflop){\
		this->routes.at(this->defaultRoute)->GET(socket,path->cstr(this->routes.at(this->defaultRoute)->getName().lenght(),path->lenght()),data);\
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