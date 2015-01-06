#include "actor.h"
#include <iostream>
#include <string>
using namespace lab3;
Actor::Actor(Environment& location) {

	this->location = &location;
	get_location()->add_actor(this);
}
std::string Actor::get_type() {
	//TODO
	return type;
}

std::string Actor::action() {
	//TODO
	//walk in direction or fight
	// if fight then fight else
	Actor* another_actor = another_actor_in_range();
	if(another_actor != NULL){
		fight(another_actor);
		return "Actor fought another actor";
	}
	else {
		set_location(*(get_location()->getNeighbor(move_next)));
		if(went_west){
			move_next="east";
			went_west=false;
			return "actor went west";	
		} else {
			move_next="west";
			went_west=true;
			return "actor went east";
		}
	}
	//return a string of what happend.
	return "";
}

void Actor::go(std::string direction) {
	//TODO
}

void Actor::fight(Actor* target) {
	target->remove_health(get_attack_points());
}

std::string Actor::sense() {
	//TODO
	std::string retString = ""; 
	retString += this->get_location()->getDescription();
	std::vector<Item*> items = this->get_location()->getItems();
	if(items.begin() != items.end()){
			retString += "\n Oh look there is some random items in this env! \n";
			for(auto i = items.begin(); i!=items.end();++i){
				retString += (*i)->getName();
				retString += "\n";
			}
		} 
	return retString; //TODO
}

void Actor::use_special() {
	//TODO
}

void Actor::dead() {
	//TODO
}

void Actor::set_hp(int hp) {

	health = hp;
}

void Actor::set_attack_points(int attack_points) {
	default_attack_points = attack_points;
}

int Actor::get_attack_points() {
	return default_attack_points;
}
int Actor::get_hp() {

	return health;
}

void Actor::set_location(Environment& location){
	get_location()->remove_actor(this);
	this->location = &location;
	get_location()->add_actor(this);
}

Environment* Actor::get_location() {
	return location;
}

void Actor::remove_health(int dmg){
	if(health <= dmg) {
		health = 0;
		dead();
	} else {
		health -= dmg;
	}
}

Actor* Actor::another_actor_in_range(){
	for(Actor* actor:get_location()->get_actors()){
		if(actor != this) {
			return actor;
		}
		else{
			return NULL;
		}
	}
	std::cout <<"fel i actor:another_actor_in_range"<< std::endl;
	return NULL;
}