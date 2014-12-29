#include "swamp.h"
#include <iostream>

using namespace lab3; 

Swamp::Swamp(){

}

void Swamp::sink(){
 //TODO when a character is in the swamp it's slowly sinking.  
}

int main(){
	Swamp s; 
	std::cout<< s.weather() << std::endl;
	return 1;
}