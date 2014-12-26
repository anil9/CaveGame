#include "environment.h"
#include <iostream>
#include <string>
using namespace lab3;

	environment::environment(){
		//TODO
	}
	void environment::directions(){
		//TODO
	}
	void environment::neighbor(){
		//TODO
	}

	/*
	* Returns the description for the specific environment
	*/
	std::string environment::description(std::string env){

		return descriptions[env]; 
	}
	void environment::enter(std::string env){
		//TODO med parameter env. 
	}
	void environment::go_back(){
		///TODO
	}

int main(){
	return 0;
}