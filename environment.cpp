#include "environment.h"
#include <iostream>
#include <string>
using namespace lab3;

	Environment::Environment(std::string description){
		env_description = description;
	}

	/*
	* appends the string with the available directions and returns the string. 
	*/ 
	std::string Environment::directions(){
		std::string directions;
		if(env_neighbors.at("south") != nullptr){
			directions.append(" south");
		} if(env_neighbors.at("north") != nullptr){
			directions.append(" north");
		} if(env_neighbors.at("west") != nullptr){
			directions.append(" west");
		} if(env_neighbors.at("east") != nullptr){
			directions.append(" east");
		}
		if(env_neighbors.at("south") == nullptr && env_neighbors.at("north") == nullptr && env_neighbors.at("west") == nullptr && env_neighbors.at("east") == nullptr){
			directions.append(" No available directions");
		}
		
		return directions;
	}

	std::string Environment::description(){
		return env_description;
	}

	/*
	* Appends the neighbors to the environment and returns the string.
	*/ 
	void Environment::neighbors(){
		//TODO
	}

	void Environment::enter(Environment* env){
		//TODO med parameter env. 
	}


	void Environment::remove_item(Item* item){
		for(typename std::vector<Item*>::iterator it = items_in_env.begin(); it != items_in_env.end(); ++it){
			if(*it == item){
				items_in_env.erase(it);
			}
		}
	}

	void Environment::setDirection(std::string direction, Environment* env){
		//TODO checkar för om det finns en granne där redan? 		 	
		env_neighbors.emplace(direction, env);
		
	}

	Environment* Environment::getDirection(std::string direction){
		try{
			return env_neighbors.at(direction);
		}catch(const std::out_of_range& oor){
			return 0;
		}
	}

