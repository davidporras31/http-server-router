#include "Route.h"

Route::Route(){
	this->name = "";
}
Route::~Route(){

}

void Route::setName(std::string name){
	if (this->name == "")
		this->name = name;
}
std::string Route::getName(){
	return this->name;
}

std::string Route::getPath()
{
	return "./" + this->getName();
}
