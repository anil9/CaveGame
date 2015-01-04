#include "actor.h"
#include <iostream>
#include <string>
using namespace lab3;
Actor::Actor(Environment& location) {

	this->location = &location;
}
std::string Actor::get_type() {
	//TODO
	return type;
}

std::string Actor::action() {
	//TODO
	//walk in direction or fight
	// if fight then fight else
	set_location(*(get_location().getNeighbor(move_next)));
	if(went_west){
		move_next="east";
		went_west=false;
		return "actor went west";	
	} else {
		move_next="west";
		went_west=true;
		return "actor went east";
	}
	//return a string of what happend.
	return "";
}

void Actor::go(std::string direction) {
	//TODO
}

void Actor::fight(Actor& target) {
	target.remove_health(get_attack_points());
}

std::string Actor::sense() {
	//TODO
	return "you sense nothing"; //TODO
}

void Actor::use_special() {
	//TODO
}

void Actor::dead() {
	//TODO
}

void Actor::set_hp(int hp) {

	health = hp;
}

void Actor::set_attack_points(int attack_points) {
	default_attack_points = attack_points;
}

int Actor::get_attack_points() {
	return default_attack_points;
}
int Actor::get_hp() {

	return health;
}

void Actor::set_location(Environment& location){
	this->location = &location;
}

Environment& Actor::get_location() {
	return *location;
}

void Actor::remove_health(int dmg){
	if(health <= dmg) {
		health = 0;
		dead();
	} else {
		health -= dmg;
	}
}

/*
int main() {
	Actor test1;
	test1.set_attack_points(4);
	Actor test2;
	test2.set_hp(10);
	test1.fight(test2);
	std::cout << test2.get_hp() << std::endl;

	return 0;
}
*/