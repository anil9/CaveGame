#include "container.h"
#include <string>
using namespace lab3;

Container::Container(int capacity, int weight, std::string description): Pickup_able(weight, description){
	this->capacity = capacity;
}
std::vector<Pickup_able*> Container::containing(){		// TODO: return value. Should it be a reference to a vector?
	return contains;
}
void Container::drop(Pickup_able& pickup_able){
	// TODO remove from vector.
}
