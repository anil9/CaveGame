#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>
#include <map>
#include <vector>

namespace lab3{
class environment{
 public:
	environment(); 
	void directions();
	void neighbor();
	std::string description(std::string);
	void enter(std::string);
	void go_back();

private:
	std::map<std::string, std::string> descriptions;
	const std::vector<std::string>  env_types = {"woods", "cave", "swamp", "cabin"};  

};
}

#endif