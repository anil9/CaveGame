#include "monster.h"
#include <iostream>

using namespace lab3;


Monster::Monster(std::string name, std::string noise, Environment& location): Actor(name,location){

	this->noise = noise;
	set_attack_points(8);
	set_hp(25);
}
std::string Monster::make_noise(){
	return noise;
}

std::string Monster::fight(Actor* actor){
	std::string ret_string =Actor::fight(actor);
	ret_string+= "\n"+ get_name() + " says " + make_noise();
	return ret_string;
}

/*
int main() {

	Monster last_boss("MUAHAHAHAH");
	Monster dragon("FCHHH");
	std::cout << last_boss.make_noise() << std::endl;

	last_boss.set_attack_points(7);
	last_boss.set_hp(10);
	dragon.set_attack_points(5);
	dragon.set_hp(7);

	last_boss.fight(dragon);
	std::cout << "health of dragon after being hit: " << dragon.get_hp() << std::endl;

	return 0;
}
*/
