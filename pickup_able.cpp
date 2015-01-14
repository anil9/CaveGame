#include "pickup_able.h"
#include <string>
using namespace lab3;

Pickup_able::Pickup_able(int weight, std::string description, std::string name) : Item(description, name, true) {
	this->weight = weight;
}
Pickup_able::~Pickup_able(){}

int Pickup_able::get_weight()const{
	return weight;
}