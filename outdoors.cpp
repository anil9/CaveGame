#include "outdoors.h"
#include <iostream>
#include <string>
#include <initializer_list>

using namespace lab3; 

Outdoors::Outdoors(){}

Outdoors::Outdoors(std::string _description){
	env_description = _description;
}

Outdoors::Outdoors( std::string _description, std::initializer_list<std::string> items){
	env_description = _description; 
	items_in_env = items; 
}

std::string Outdoors::weather(){
	std::string temp = "kallt som fan";
	return temp;
}
