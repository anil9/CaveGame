#include "monster.h"
#include <iostream>

using namespace lab3;


Monster::Monster(const std::string name, std::string noise, Environment* location): Actor(name,location){

	this->noise = noise;
	set_attack_points(8);
	set_hp(25);
}
std::string Monster::use_special(){
	return noise;
}

std::string Monster::fight(Humanoid* humanoid){
	Actor* actor = dynamic_cast<Actor*>(humanoid);
	std::string ret_string =Actor::fight(actor);
	ret_string+= "\n"+ get_name() + ": " + use_special();
	return ret_string;
}

std::string Monster::action(){
	Humanoid* humanoid = humanoid_in_range();
	if(humanoid != NULL){
		return fight(humanoid);
	} 
	else {
		return Actor::action();

	}
}

Humanoid* Monster::humanoid_in_range()const{

	std::vector<Actor*> other_actors = get_location()->get_actors(); 
		for(Actor* actor:other_actors){
			Humanoid* humanoid = dynamic_cast<Humanoid*>(actor);
			if(humanoid != NULL) {
				return humanoid;
			}
		}
	return NULL;
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
