#include "animal.h"

using namespace lab3;
Animal::Animal(std::string name, Environment& location) : Actor(name, location) {
	//TODO
	set_attack_points(2);
	set_hp(10);
}
void Animal::eat() {
	//TODO
}
