#include "obstacle.h"
#include <string>
using namespace lab3;

Obstacle::Obstacle(bool movable, std::string description, std::string name) : Item(description, name, false) {
	this->movable = movable;
}
bool Obstacle::is_movable()const{
	return movable;
}