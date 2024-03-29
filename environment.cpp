#include "environment.h"
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

using namespace lab3;

	Environment::Environment(std::string description){
		env_description = description;
	}
	Environment::Environment(std::string description, std::vector<Item*> items){
		env_description = description;
		items_in_env = items;
	}

	/*
	* appends the string with the available directions and returns the string. 
	*/ 
	std::string Environment::directions(){
		std::string directions;
		if(env_neighbors.at("south") != NULL){
			directions.append(" south");
		} if(env_neighbors.at("north") != NULL){
			directions.append(" north");
		} if(env_neighbors.at("west") != NULL){
			directions.append(" west");
		} if(env_neighbors.at("east") != NULL){
			directions.append(" east");
		}
		if(env_neighbors.at("south") == NULL && env_neighbors.at("north") == NULL && env_neighbors.at("west") == NULL && env_neighbors.at("east") == NULL){
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

	void Environment::setDirection(std::string direction, Environment& env){
		//TODO checkar för om det finns en granne där redan? 
		Environment* envp = &env;		 	
		env_neighbors[direction]=envp;
		
	}

	Environment* Environment::getDirection(std::string direction){
		try{
			return env_neighbors.at(direction);
		}catch(const std::out_of_range& oor){
			return 0;
		}
	}

