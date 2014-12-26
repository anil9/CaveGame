#include "actor.h"
#include <iostream>
#include <string>
using namespace lab3;
actor::actor() {

	//TODO
}
std::string actor::get_type() {
	//TODO
	return type;
}

void actor::action() {
	//TODO
}

void actor::go(std::string direction) {
	//TODO
}

void actor::fight(actor& target) {
	target.remove_health(get_attack_points());
}

std::string actor::sense() {
	//TODO
	return "you sense nothing"; //TODO
}

void actor::use_special() {
	//TODO
}

void actor::dead() {
	//TODO
}

void actor::set_hp(int hp) {

	health = hp;
}

void actor::set_attack_points(int attack_points) {
	default_attack_points = attack_points;
}

int actor::get_attack_points() {
	return default_attack_points;
}
int actor::get_hp() {

	return health;
}

// Private:
void actor::remove_health(int dmg){
	if(health <= dmg) {
		health = 0;
		dead();
	} else {
		health -= dmg;
	}
}


int main() {
	actor test1;
	test1.set_attack_points(4);
	actor test2;
	test2.set_hp(10);
	test1.fight(test2);
	std::cout << test2.get_hp() << std::endl;

	return 0;
}