#include "swamp.h"
#include <iostream>
#include <string>

using namespace lab3; 

Swamp::Swamp(bool _south, bool _north, bool _west, bool _east, std::string _description){
	south = _south;
	north = _north;
	west = _west;
	east = _east; 

	env_description = _description;


}

void Swamp::sink(){
 //TODO when a character is in the swamp it's slowly sinking.  
}

int main(){
	Swamp s = Swamp(false, false, false, false, "detta är ett träsk"); 
	std::cout<< s.weather() << std::endl;
	std::cout<< s.description() << std::endl;
	return 1;
}