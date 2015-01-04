#include "unwearable.h"
#include <string>

using namespace lab3;

Unwearable::Unwearable(std::string use_text, int weight, std::string description, std::string name): Pickup_able(weight, description, name) {
	this->use_text = use_text;
}

std::string Unwearable::use() {
	return use_text;
}