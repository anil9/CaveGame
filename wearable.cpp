#include "wearable.h"

using namespace lab3;

Wearable::Wearable(int weight, std::string description, std::string name, std::string type) : Pickup_able(weight, description, name){
	this->type = type;
}

Wearable::~Wearable(){}

std::string Wearable::get_type()const{
	return type;
}
