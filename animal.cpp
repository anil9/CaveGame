#include "animal.h"

using namespace lab3;
Animal::Animal(std::string name, Environment& location) : Actor(name, location) {
	//TODO
	set_attack_points(2);
	set_hp(10);
}
std::string Animal::use_special() {
	int inc_hp_val=4;
	increase_hp(inc_hp_val);
	return get_name() + " is eating. Increasing health by " + std::to_string(inc_hp_val) + " hp: " + std::to_string(get_hp());
}
std::string Animal::action(){
	if(get_hp() < 8) {
		return use_special();
	} else {
		return Actor::action();
	}

}
