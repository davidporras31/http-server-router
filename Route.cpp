#include "Route.h"

Route::Route(){
	this->name = "";
	this->redirected = false;
}
Route::~Route(){

}

void Route::setName(std::string name){
	this->name = name;
}
std::string Route::getName(){
	return this->name;
}

bool Route::isRedirected()
{
	return this->redirected;
}

void Route::setRedirected(bool redirected)
{
	this->redirected = redirected;
}
