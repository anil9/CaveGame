#include "swamp.h"
#include <iostream>
#include <string>

using namespace lab3; 

Swamp::Swamp(std::string _description): Outdoors(_description){}


void Swamp::sink(const Actor* a){
 //TODO when a character is in the swamp it's slowly sinking.  
	//(*a).remove_health(1);
}
/*
int main(){
	Swamp s = Swamp("detta är ett träsk"); 
	std::cout<< s.weather() << std::endl;
	std::cout<< s.description() << std::endl;
	return 1;
}
*/