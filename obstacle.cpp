#include "obstacle.h"
#include <string>
using namespace lab3;

Obstacle::Obstacle(std::string locked_description,std::string unlocked_description) : Environment(unlocked_description) {
	
	this->locked_description = locked_description;
}
bool Obstacle::is_locked()const{
	return locked;
}

void Obstacle::set_backtrack_direction(std::string direction, Environment* neighbor){
	Environment::setDirection(direction, neighbor);
}

void Obstacle::setDirection(std::string direction, Environment* neighbor){
	hidden_neighbors[direction] = neighbor;
}
void Obstacle::unlock(){
	locked = false;
	for(auto it = hidden_neighbors.begin(); it!=hidden_neighbors.end(); ++it){
		Environment::setDirection(it->first,it->second);
	}
}

std::string Obstacle::getDescription()const{
	if(is_locked()){
		return locked_description;
	} else {
		return Environment::getDescription();
	}
}