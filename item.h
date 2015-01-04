#ifndef ITEM_H
#define ITEM_H
#include <string>

namespace lab3{
class Item{
 public:
	Item(std::string, std::string, bool); 
	std::string get_description();
	bool operator==(const Item*) const;
	std::string getName();
	virtual ~Item();
	bool isPickupable();

private:
	std::string description; 
	std::string name; 
	bool pickup_able = false;

};
}

#endif