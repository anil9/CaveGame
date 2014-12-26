#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>
#include <map>

namespace lab3{
class environment{
 public:
	environment(); 
	void directions();
	void neighbor();
	std::string description(std::string);
	void enter();
	void go_back();

private:
	std::map<std::string, std::string> descriptions; 

};
}

#endif