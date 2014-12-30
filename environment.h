#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>
#include <map>
#include <vector>

namespace lab3{
class Environment{
 protected:
 	Environment(); 
	
 public:
	std::string directions();
	std::string neighbors();

	std::string description();
	void enter(std::string);
	void go_back();
	void drop(std::string);
	void pick_up(std::string); 

protected:
	bool south = false, north = false, east = false, west = false; 
	std::vector<std::string> env_neighbors;
	std::vector<std::string> items_in_env; 
	std::string env_description; 
};
}

#endif