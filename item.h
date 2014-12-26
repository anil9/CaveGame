#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <map>

namespace lab3{
class environment{
 public:
	environment(); 
	std::string description(std::string);

private:
	std::map<std::string, std::string> descriptions; 

};
}

#endif