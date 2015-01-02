#include "item.h"
#include <iostream>
#include <string>
using namespace lab3;

	Item::Item(std::string description){
		this->description = description;
		//TODO
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
