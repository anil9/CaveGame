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
	
	Pickup_able* pa = dynamic_cast<Pickup_able*>(item);
	if(mybag.pick_up(pa)){
		get_location()->remove_item(item); 
	}

}
		
void Humanoid::drop(Item* dropping_item){
	Pickup_able* pa = dynamic_cast<Pickup_able*>(dropping_item); 
	if(mybag.drop(pa)){
		get_location()->add_item(dropping_item);
	}	
}

Container& Humanoid::get_container(){
	return mybag;
}

