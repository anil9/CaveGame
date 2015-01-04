#include "outdoors.h"
#include <iostream>
#include <string>
#include <initializer_list>
#include <stdlib.h>

using namespace lab3; 

Outdoors::Outdoors(std::string _description): Environment(_description){}


Outdoors::Outdoors( std::string _description, std::vector<Item*> items): Environment(_description, items){
	items_in_env = items;
}

std::string Outdoors::weather(){
	int i = rand()%5+1;
	return weather_description.at(i);
}
