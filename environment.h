#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>
#include <map>
#include <vector>
#include "item.h"


namespace lab3{
class Environment{
 	 
	
 public:
 	Environment(std::string);
 	Environment(std::string,std::vector<Item*>);
	std::string directions();
	void neighbors();

	std::string description();
	void enter(Environment*);
	void remove_item(Item*);
	void setDirection(std::string, Environment&);
	Environment* getDirection(std::string);

protected:
	std::map<std::string, Environment*> env_neighbors;
	std::vector<Item*> items_in_env; 
	std::string env_description; 
};
}

#endif