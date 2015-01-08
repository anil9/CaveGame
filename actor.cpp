#include "actor.h"
#include <iostream>
#include <string>
using namespace lab3;
Actor::Actor(std::string name, Environment& location) {
	this->name = name;
	this->location = &location;
	get_location()->add_actor(this);
}
std::string Actor::get_type() {
	//TODO
	return type;
}

std::string Actor::get_name(){
	return name;
}

std::string Actor::action() {
	//TODO
	//walk in direction or fight
	// if fight then fight else
	Actor* another_actor = another_actor_in_range();
	if(another_actor != NULL){
		fight(another_actor);
		return get_name() + " fought " + another_actor->get_name() + ".";
	}
	else {
		set_location(*(get_location()->getNeighbor(move_next)));
		if(went_west){
			move_next="east";
			went_west=false;
			return get_name() + " went west";	
		} else {
			move_next="west";
			went_west=true;
			return get_name() + " went east";
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
		retString += "Oh look there is some random items in this env!";
		for(auto i = items.begin(); i!=items.end();++i){
				retString += "\n";
				retString += (*i)->getName();
		}
		retString += "\n";
	}
	Actor* another_actor = another_actor_in_range();
	if(another_actor != NULL) {
		retString += "There's someone here: " + another_actor->get_name();
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
	std::vector<Actor*> other_actors = get_location()->get_actors(); 
	for(Actor* actor:other_actors){
		if(actor != this) {
			return actor;
		}
	}
	return NULL;
}
/*
int main() {
	Actor test1;
	test1.set_attack_points(4);
	Actor test2;
	test2.set_hp(10);
	test1.fight(test2);
	std::cout << test2.get_hp() << std::endl;

	return 0;
}
*/