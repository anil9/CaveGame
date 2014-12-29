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

	//description ska vara pure virtual, är inte det nu pga testning.
	std::string description(std::string);
	void enter(std::string);
	void go_back();
	void drop(std::string);
	void pick_up(std::string); 

private:
	bool south = false, north = false, east = false, west = false; 
	std::vector<std::string> env_neighbors;
	std::vector<std::string> items_in_env; 
	std::map<std::string, std::string> env_description;
};
}

#endif