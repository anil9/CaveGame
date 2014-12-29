#include "humanoid.h"
#include <iostream>

using namespace lab3;

Humanoid::Humanoid(std::string name): Actor() {
	this->name = name;
}
void Humanoid::change_gear(Wearable& wearable) {
	//todo
}
void Humanoid::talk_to(Actor& actor) {
	//todo
}
void Humanoid::pick_up(Pickup_able& picked_up) {
	// convert "pick up <sword of awesome>"-string to instance: Weapon awesome_sword
	// then add to possession vector
}
std::string Humanoid::get_name() {
	return name;
}
void Humanoid::drop(Pickup_able& dropping_item){
	//convert "drop <sword of awesome>"-string to instance: Weapon awesome_sword
}


