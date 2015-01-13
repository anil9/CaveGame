#include "unwearable.h"
#include <string>

using namespace lab3;

Unwearable::Unwearable(std::string use_text, int weight, std::string description, std::string name): Pickup_able(weight, description, name) {
	this->use_text = use_text;
}

std::string Unwearable::use() {
	return use_text;
}
void Unwearable::set_key(Obstacle* unlocks){
	this->unlocks = unlocks;
	key = true;
}
bool Unwearable::open(Environment* location){
	if(key){
		Obstacle* obstacle = dynamic_cast<Obstacle*>(location);
		if(obstacle!= NULL){
			if(obstacle == get_unlocking_obstacle() && obstacle->is_locked()){
				obstacle->unlock();
				return true;
			}
		}

	}
		return false;
}

bool Unwearable::is_key()const{
	return key;
}
Obstacle* Unwearable::get_unlocking_obstacle()const{
	return unlocks;
}