#include "environment.h"
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <algorithm>

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


	void Environment::remove_item(Item* item){
		for(int i=0; i< items_in_env.size();++i){
			if(items_in_env[i] == item){
				items_in_env.erase(items_in_env.begin() + i);
			}
		}
	}
	void Environment::add_item(Item* item){
		items_in_env.push_back(item);
	}

	void Environment::setDirection(std::string direction, Environment& env){
		//TODO checkar för om det finns en granne där redan? 		 	
		env_neighbors[direction]=&env;
		
	}

	Environment* Environment::getDirection(std::string direction){
		try{
			return env_neighbors.at(direction);
		}catch(const std::out_of_range& oor){
			return 0;
		}
	}

	Environment* Environment::getNeighbor(std::string neighbor){
		return env_neighbors[neighbor];
	}

	Item* Environment::getItem(std::string item){
		for(unsigned int i = 0; i<items_in_env.size(); ++i){
			if((items_in_env[i])->getName() ==item){
				return items_in_env[i];
			}
		}
		return NULL;
	}

	std::string Environment::getDescription(){
		return env_description;
	}

	std::vector<Item*> Environment::getItems(){
		return items_in_env;
	}
	void Environment::add_actor(Actor* actor) {
		actors_in_env.push_back(actor);

	}
	void Environment::remove_actor(Actor* actor){
		actors_in_env.erase(std::remove(actors_in_env.begin(), actors_in_env.end(), actor), actors_in_env.end());

	}
	std::vector<Actor*> Environment::get_actors() {
		return actors_in_env;
	}
