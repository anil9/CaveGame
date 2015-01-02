#include "outdoors.h"
#include <iostream>
#include <string>
#include <initializer_list>

using namespace lab3; 

Outdoors::Outdoors(std::string _description): Environment(_description){}


Outdoors::Outdoors( std::string _description, std::initializer_list<Item*> items): Environment(_description){
	items_in_env = items; 
}

std::string Outdoors::weather(){
	std::string temp = "kallt som fan";
	return temp;
}
