#include "wearable.h"

using namespace lab3;

Wearable::Wearable(int weight, std::string description, std::string name, std::string type) : Pickup_able(weight, description, name){
	this->type = type;
}
std::string Wearable::get_type(){
	return type;
}