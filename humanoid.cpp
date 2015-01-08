#include "humanoid.h"
#include <iostream>

using namespace lab3;

Humanoid::Humanoid(std::string name, Environment& location): Actor(name,location), mybag(50) {
}
void Humanoid::change_gear(Wearable& wearable) {
	//todo
}
void Humanoid::talk_to(Actor& actor) {
	//todo
}
void Humanoid::pick_up(Item* item) {
	
	get_location()->remove_item(item);
	Pickup_able* pa = dynamic_cast<Pickup_able*>(item); 
	mybag.pick_up(pa);
}
		
void Humanoid::drop(Item* dropping_item){
	//convert "drop <sword of awesome>"-string to instance: Weapon awesome_sword
	Pickup_able* pa = dynamic_cast<Pickup_able*>(dropping_item); 
	mybag.drop(pa);
	get_location()->add_item(dropping_item);
}


