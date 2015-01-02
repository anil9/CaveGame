#include "indoors.h"
#include <string>
#include <initializer_list>

using namespace lab3;

Indoors::Indoors(std::string _description): Environment(_description){}



Indoors::Indoors(std::string _description, std::initializer_list<Item> items): Environment(_description){
	items_in_env = items; 
}
