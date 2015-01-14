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
	Environment::~Environment(){}

	/*
	* appends the string with the available directions and returns the string. 
	*/ 
	std::string Environment::directions()const{
		std::string directions="";
		if(env_neighbors.find("south") != env_neighbors.end()){
			directions+=" south";
		} if(env_neighbors.find("north") != env_neighbors.end()){
			directions+=" north";
		} if(env_neighbors.find("west") != env_neighbors.end()){
			directions+=" west";
		} if(env_neighbors.find("east") != env_neighbors.end()){
			directions+=" east";
		}
		if(directions==""){
			directions+=" No available directions";
		}
		
		return directions;
	}

	void Environment::remove_item(Item* item){
		for(unsigned int i=0; i< items_in_env.size();++i){
			if(items_in_env[i] == item){
				items_in_env.erase(items_in_env.begin() + i);
			}
		}
	}
	void Environment::add_item(Item* item){
		items_in_env.push_back(item);
	}

	void Environment::setDirection(std::string direction, Environment* env){
		//TODO checkar för om det finns en granne där redan? 		 	
		env_neighbors[direction]=env;
		
	}

	Environment* Environment::getNeighbor(std::string neighbor){
		if(env_neighbors.find(neighbor) != env_neighbors.end()){
			return env_neighbors[neighbor];
		}
		else{
			return NULL;
		}
	}

	Item* Environment::getItem(std::string item)const{
		
		for(unsigned int i = 0; i<items_in_env.size(); ++i){
			if((items_in_env[i])->getName() ==item){
				return items_in_env[i];
			}
		}
		return NULL;
	}

	std::string Environment::getDescription()const{
		return env_description;
	}

	std::vector<Item*> Environment::getItems()const{
		return items_in_env;
	}
	void Environment::add_actor(Actor* actor) {
		actors_in_env.push_back(actor);

	}
	void Environment::remove_actor(Actor* actor){
		actors_in_env.erase(std::remove(actors_in_env.begin(), actors_in_env.end(), actor), actors_in_env.end());

	}

	Actor* Environment::get_actor(std::string actor_name)const{
		for(Actor* actor: actors_in_env){
			std::string name = actor->get_name();
			std::transform(name.begin(), name.end(), name.begin(), ::tolower);
			if(name == actor_name){
				return actor;
			}
		}
		return NULL;
	}

	std::vector<Actor*> Environment::get_actors()const{
		return actors_in_env;
	}
