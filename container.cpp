#include "container.h"
#include <string>
using namespace lab3;

Container::Container(int capacity, int weight, std::string description): Pickup_able(weight, description){
	this->capacity = capacity;
}
vector<Pickup_able&> Container::containing(){
	return contains;
}
void Container::drop(Pickup_able& pickup_able){
	// TODO remove from vector.
}