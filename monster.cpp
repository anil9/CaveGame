#include "monster.h"
#include <iostream>

using namespace lab3;


Monster::Monster(std::string name, std::string noise, Environment& location): Actor(name,location){

	this->noise = noise;
}
std::string Monster::make_noise(){
	return noise;
}

void Monster::fight(Actor* actor){
	Actor::fight(actor);
	std::cout << get_name() << " says " << make_noise() << "\n";
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
