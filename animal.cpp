#include "animal.h"

using namespace lab3;
Animal::Animal(std::string name, Environment* location) : Actor(name, location){
	set_attack_points(2);
	set_hp(10);
	set_maxhp(10);
}

Animal::~Animal(){}
std::string Animal::use_special() {
	int inc_hp_val=6;
	increase_hp(inc_hp_val);
	return get_name() + " is eating. Increasing health by " + std::to_string(inc_hp_val) + " hp: " + std::to_string(get_hp());
}
std::string Animal::action(){
	
	if(get_hp() < 8) {
		return use_special();
	} else {
		Indoors* next_location_indoors = dynamic_cast<Indoors*>(get_location()->getNeighbor(moving_next()));
		if(next_location_indoors != NULL) {	// next_location is indoors
			change_direction();
		}
		return Actor::action();
	}

}
