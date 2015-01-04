#ifndef ITEM_H
#define ITEM_H
#include <string>

namespace lab3{
class Item{
 public:
	Item(std::string); 
	std::string get_description();
	bool operator==(const Item*) const;
	std::string getName();
private:
	std::string description; 
	std::string name; 

};
}

#endif