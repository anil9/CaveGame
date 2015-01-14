#include "container.h"
#include <string>
#include <vector>
#include <iostream>
using namespace lab3;

Container::Container(int capacity):Item("mybag", "bag", false){
	this->capacity = capacity;
}
Container::~Container(){}

std::vector<Pickup_able*> Container::containing()const{		// TODO: return value. Should it be a reference to a vector?
	return contains;
}
bool Container::drop(Pickup_able* pickup_able){
	
	for(unsigned int i=0; i<contains.size(); ++i){
		if(pickup_able==contains[i]){
			contains.erase(contains.begin()+i);
			used -= pickup_able->get_weight();
			return true;
		}
	}
	return false;
}

bool Container::pick_up(Pickup_able* pickup_able){
	if(capacity >= used + pickup_able->get_weight()){
		used += pickup_able->get_weight();
		contains.push_back(pickup_able);
		return true;
	}
	std::cout<<"Your bag gets to heavy!"<<std::endl;
	return false;
}

Pickup_able* Container::get_item(std::string item_name)const{
	for(Pickup_able* item: contains){
		if(item->getName() == item_name){
			return item;
		}
	}
	return NULL;
}

std::string Container::get_items()const{
	std::string ret = "";
	int total_weight = 0;
	if(contains.size() == 0){
		return "the bag is empty!";
	}
	for(Pickup_able* item: contains){
		ret += item->getName();
		ret += "   ";
		ret += std::to_string(item->get_weight());
		ret += "   ";
		ret += item->get_description();
		ret += "\n";
		total_weight += item->get_weight();
	}
	ret += "Total weight of bag is ";
	ret += std::to_string(total_weight);
	ret += "\nThe capacity of the bag is: ";
	ret += std::to_string(capacity);

	return ret;

}


