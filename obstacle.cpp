#include "obstacle.h"
#include <string>
using namespace lab3;

Obstacle::Obstacle(bool movable, std::string description) : Item(description) {
	this->movable = movable;
}
bool Obstacle::is_movable() {
	return movable;
}