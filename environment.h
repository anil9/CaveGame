#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>
#include <map>
#include <vector>
#include "item.h"
#include "actor.h"




namespace lab3{
class Actor;
class Environment{
 	 
	
 public:
 	Environment(std::string);
 	Environment(std::string,std::vector<Item*>);
 	virtual ~Environment();
	std::string directions()const;
	void remove_item(Item*);
	void add_item(Item*);
	virtual void setDirection(std::string, Environment*);
	Environment* getNeighbor(std::string);
	virtual std::string getDescription()const;
	Item* getItem(std::string)const;
	std::vector<Item*> getItems()const;
	void add_actor(Actor*);
	void remove_actor(Actor*);
	Actor* get_actor(std::string)const;
	std::vector<Actor*> get_actors()const;

protected:
	std::map<std::string, Environment*> env_neighbors;
	std::vector<Item*> items_in_env; 
	std::vector<Actor*> actors_in_env;
	std::string env_description;

};
}

#endif
