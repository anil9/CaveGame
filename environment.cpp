#include "environment.h"
#include <iostream>
#include <string>
using namespace lab3;

	Environment::Environment(){
		//TODO
	}

	/*
	* appends the string with the available directions and returns the string. 
	*/ 
	std::string Environment::directions(){
		std::string directions;
		if(south == true){
			directions.append(" south");
		} if(north == true){
			directions.append(" north");
		} if(west == true){
			directions.append(" west");
		} if(east == true){
			directions.append(" east");
		}
		if(south == false && north == false && west == false && east == false){
			directions.append(" No available directions");
		}
		
		return directions;
	}

	/*
	* Appends the neighbors to the environment and returns the string.
	*/ 
	std::string Environment::neighbors(){
		std::string temp;
		for(unsigned int i = 0; i< env_neighbors.size(); ++i){
			temp.append(env_neighbors.at(i));
			temp.append(" ");
		}
		return temp;
	}

	void Environment::enter(std::string env){
		//TODO med parameter env. 
	}
	void Environment::go_back(){
		///TODO
	}

	void Environment::drop(std::string item){

	}

	void Environment::pick_up(std::string item){

	}

