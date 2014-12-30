#ifndef PICKUP_ABLE
#define PICKUP_ABLE
#include "item.h"
#include <string>
namespace lab3{

class Pickup_able: public Item{
public:
	Pickup_able(int, std::string);
	int get_weight();



private:
	int weight;
};
}

#endif