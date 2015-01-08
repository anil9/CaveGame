#include "humanoid.h"
#include <iostream>

using namespace lab3;

Humanoid::Humanoid(std::string name, Environment& location): Actor(name,location) {
	set_attack_points(5);
	set_hp(30);
}
void Humanoid::change_gear(Wearable& wearable) {
	//todo
}
void Humanoid::talk_to(Actor& actor) {
	//todo
}
void Humanoid::pick_up(Item* item) {
	
	Pickup_able* pa = dynamic_cast<Pickup_able*>(item);
	if(get_container().pick_up(pa)){
		get_location()->remove_item(item); 
	}

}
		
void Humanoid::drop(Item* dropping_item){
	Pickup_able* pa = dynamic_cast<Pickup_able*>(dropping_item); 
	if(get_container().drop(pa)){
		get_location()->add_item(dropping_item);
	}	
}

std::string Humanoid::get_answer(){
	return answer;
}
void Humanoid::set_answer(std::string new_answer){
	answer = new_answer;
}

