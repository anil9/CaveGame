#include "item.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace lab3;

	Item::Item(std::string description, std::string name, bool pickup_able){
		this->description = description;
		std::transform(name.begin(), name.end(), name.begin(), ::tolower);
		this->name = name;
		this->pickup_able = pickup_able;
	}
	
	/*
	* Returns the description of the item.
	*/
	std::string Item::get_description(){

		return description; 
	}

	bool Item::operator==(const Item* it)const{
			return (*this).description == (*it).description;
	}

	std::string Item::getName(){
		return name;
	}

	Item::~Item(){}

	bool Item::isPickupable(){
		return pickup_able;
	}