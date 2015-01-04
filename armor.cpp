#include "armor.h"
#include <string>

using namespace lab3;
Armor::Armor(int protection, int max_durability, int weight, std::string description, std::string name): Wearable(weight, description, name){
	this->protection = protection;
	this->max_durability = max_durability;
}
int Armor::get_max_durability(){
	return max_durability;
}
int Armor::get_current_durability(){
	return current_durability;
}
int Armor::get_protection(){
	if(current_durability > 0) {
		return protection;
	} else {
		return 0;
	}
}
void Armor::set_current_durability(int durability) {
	if (durability <= max_durability && durability >= 0) {
		current_durability = durability;
	}
}