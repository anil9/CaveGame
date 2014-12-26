#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>
#include <map>
#include <vector>

namespace lab3{
class environment{
 public:
	environment(); 
	std::string directions();
	std::string neighbors();

	//description ska vara pure virtual, är inte det nu pga testning.
	std::string description(std::string);
	void enter(std::string);
	void go_back();

private:
	bool south = false, north = false, east = false, west = false; 
	std::vector<std::string> env_neighbors;
};
}

#endif