#include "armor.h"
#include <string>

using namespace lab3;
Armor::Armor(int protection, int weight, std::string description, std::string name, std::string type): Wearable(weight, description, name, type){
	this->protection = protection;
}
int Armor::get_protection(){
	return protection;
	
}

std::string Armor::get_stats(){
	return " hp: " + std::to_string(get_protection());
}