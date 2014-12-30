#include "pickup_able.h"
#include <string>
using namespace lab3;

Pickup_able::Pickup_able(int weight, std::string description) : Item(description) {
	this->weight = weight;
}

int Pickup_able::get_weight() {
	return weight;
}