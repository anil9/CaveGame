#include "item.h"
#include <iostream>
#include <string>
namespace lab3{
	item::item(){
		//TODO
	}
	
	/*
	* Returns the description for the specific environment
	*/
	std::string environment::description(std::string item){

		return descriptions[item]; 
	}
}