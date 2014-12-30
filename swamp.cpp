#include "swamp.h"
#include <iostream>
#include <string>

using namespace lab3; 

Swamp::Swamp(std::string _description){
	env_description = _description;
}

void Swamp::sink(){
 //TODO when a character is in the swamp it's slowly sinking.  
}

int main(){
	Swamp s = Swamp("detta är ett träsk"); 
	std::cout<< s.weather() << std::endl;
	std::cout<< s.description() << std::endl;
	return 1;
}