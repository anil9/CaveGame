#include "environment.h"
#include <iostream>
#include <string>
namespace lab3{
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
	void environment::enter(){
		//TODO med parameter env.
	}
	void environment::go_back(){
		//TODO
	}

}