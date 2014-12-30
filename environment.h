#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>
#include <map>
#include <vector>

namespace lab3{
class Environment{
 protected:
 	Environment(std::string); 
	
 public:
	std::string directions();
	void neighbors();

	std::string description();
	void enter(Environment*);
	void go_back();
	void drop(std::string);
	void pick_up(std::string); 
	void setDirection(std::string, Environment*);
	Environment* getDirection(std::string);

protected:
	std::map<std::string, Environment*> env_neighbors;
	std::vector<std::string> items_in_env; 
	std::string env_description; 
};
}

#endif