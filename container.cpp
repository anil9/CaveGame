#include "container.h"
#include <string>
using namespace lab3;

Container::Container(int capacity):Item("mybag", "bag", false){
	this->capacity = capacity;
}
std::vector<Pickup_able*> Container::containing(){		// TODO: return value. Should it be a reference to a vector?
	return contains;
}
bool Container::drop(Pickup_able* pickup_able){
	// TODO remove from vector.
	/*
	for(auto i = contains.begin(); i != contains.end(); ++i){
		if(*i == pickup_able){
			contains.erase(i);
			used -= pickup_able->get_weight();
			return true;
		}
	}
	*/
	for(int i=0; i<contains.size(); ++i){
		if(pickup_able==contains[i]){
			contains.erase(contains.begin()+1);
			used -= pickup_able->get_weight();
			return true;
		}
	}

	return false;
}

bool Container::pick_up(Pickup_able* pickup_able){
	if(capacity < used + pickup_able->get_weight()){
		return false;
	}
	used += pickup_able->get_weight();
	contains.push_back(pickup_able);
	return true;
}


