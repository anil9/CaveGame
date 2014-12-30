#include "indoors.h"
#include <string>
#include <initializer_list>

using namespace lab3;

Indoors::Indoors(bool _south, bool _north, bool _west, bool _east, std::string _description){
	south = _south;
	north = _north;
	west = _west;
	east = _east;

	env_description = _description;

}


Indoors::Indoors(bool _south, bool _north, bool _west, bool _east, std::string _description, std::initializer_list<std::string> items){
	south = _south;
	north = _north;
	west = _west;
	east = _east;

	env_description = _description;
	items_in_env = items; 
}

int main(){

	return 1;
}