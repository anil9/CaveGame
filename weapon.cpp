#include "weapon.h"
#include <string>
using namespace lab3;

Weapon::Weapon(int dmg, int weight, std::string description): Wearable(weight, description){
	damage = dmg;
}
std::string Weapon::get_effect(){
	return effect;
}
void Weapon::set_effect(std::string effect){
	this->effect = effect;
}