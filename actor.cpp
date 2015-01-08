#include "actor.h"
#include <iostream>
#include <string>
using namespace lab3;
Actor::Actor(std::string name, Environment& location): bag(50) {
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
		return fight(another_actor);
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

std::string Actor::fight(Actor* target) {
	target->remove_health(get_attack_points());
	std::string ret_string = get_name() + " fought " + target->get_name() + "\n";
	ret_string+= get_name() + "'s hp: " + std::to_string(get_hp()) + " " + target->get_name() + "'s hp: " + std::to_string(target->get_hp()) + "\n";
	if(target->get_hp() == 0) {
		ret_string+= target->get_name() + " is dead.\n";
	}
	return ret_string; 
}

std::string Actor::sense() {
	//TODO
	std::string retString = ""; 
	retString += this->get_location()->getDescription();
	auto items = this->get_location()->getItems();
	if(items.begin() != items.end()){
		retString += "Oh look there is some random items in this env!";
		
		for(auto i = items.begin(); i!=items.end();++i){
				retString += "\n";
				retString += (*i)->getName();
		}
	}
	std::string other_actors = other_actors_in_range();
	if(other_actors != "") {
		retString += "\nThere's someone here: " + other_actors;
	} 
	return retString; //TODO
}

void Actor::use_special() {
	//TODO
}

void Actor::die() {
	get_location()->remove_actor(this);
	dead = true;
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
		die();
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

std::string Actor::other_actors_in_range(){
	std::vector<Actor*> other_actors = get_location()->get_actors();
	std::string ret_string ="";
	for(Actor* actor:other_actors){
		if(actor != this) {
			ret_string+= actor->get_name() + " ";
		}
	}
	return ret_string;
}

Container& Actor::get_container(){
	return bag;
}

void Actor::set_container(Pickup_able* item){
	bag.pick_up(item);
}
bool Actor::is_dead(){
	return dead;
}
