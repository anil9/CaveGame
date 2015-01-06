#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>
#include <map>
#include <vector>
#include "item.h"



namespace lab3{
class Actor;
class Environment{
 	 
	
 public:
 	Environment(std::string);
 	Environment(std::string,std::vector<Item*>);
	std::string directions();
	
	std::string description();
	void remove_item(Item*);
	void setDirection(std::string, Environment&);
	Environment* getDirection(std::string);
	Environment* getNeighbor(std::string);
	Item* getItem(std::string);
	void add_actor(Actor*);
	void remove_actor(Actor*);
	std::vector<Actor*> get_actors();

protected:
	std::map<std::string, Environment*> env_neighbors;
	std::vector<Item*> items_in_env; 
	std::vector<Actor*> actors_in_env;
	std::string env_description;

};
}

#endif