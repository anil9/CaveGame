#include "armor.h"
#include <string>

using namespace lab3;
Armor::Armor(int protection, int max_durability, int weight, std::string description, std::string name, std::string type): Wearable(weight, description, name, type){
	this->protection = protection;
	this->max_durability = max_durability;
}
int Armor::get_max_durability()const{
	return max_durability;
}
int Armor::get_current_durability()const{
	return current_durability;
}
int Armor::get_protection()const{
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

std::string Armor::get_stats()const{
	return " hp: " + std::to_string(get_protection());
}