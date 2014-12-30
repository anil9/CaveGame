#include "outdoors.h"
#include <iostream>
#include <string>
#include <initializer_list>

using namespace lab3; 

Outdoors::Outdoors(){}

Outdoors::Outdoors(bool _south, bool _north, bool _west, bool _east, std::string _description){
	south = _south;
	north = _north;
	west = _west;
	east = _east;
	env_description = _description;
}

Outdoors::Outdoors(bool _south, bool _north, bool _west, bool _east, std::string _description, std::initializer_list<std::string> items){
	south = _south;
	north = _north;
	west = _west;
	east = _east;
	env_description = _description; 
	items_in_env = items; 
}

std::string Outdoors::weather(){
	std::string temp = "kallt som fan";
	return temp;
}
