#include "unwearable.h"
#include <string>

using namespace lab3;

Unwearable::Unwearable(std::string use_text, int weight, std::string description): Pickup_able(weight, description) {
	this->use_text = use_text;
}

std::string Unwearable::use() {
	return use_text;
}