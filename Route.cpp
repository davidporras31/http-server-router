#include "Route.h"

Route::Route(){
	this->name = "";
}
Route::~Route(){

}

void Route::setName(std::string name){
	this->name = name;
}
std::string Route::getName(){
	return this->name;
}