#ifndef ITEM_H
#define ITEM_H
#include <string>

namespace lab3{
class Item{
 public:
	Item(std::string); 
	std::string get_description();

private:
	std::string description; 

};
}

#endif