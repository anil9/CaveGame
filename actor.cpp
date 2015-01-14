#include "actor.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace lab3;
Actor::Actor(const std::string _name, Environment* location): bag(50),name(_name) {
	this->location = location;
	get_location()->add_actor(this);
}
Actor::~Actor(){}
std::string Actor::get_type() {
	//TODO
	return type;
}

const std::string Actor::get_name()const{
	return name;
}

std::string Actor::action() {
	//walk in direction or fight
	// if fight then fight else
	Actor* another_actor = another_actor_in_range();
	if(another_actor != NULL){	
		return fight(another_actor);
	}
	else if(get_name()!="Hoccar"){
		set_location(get_location()->getNeighbor(move_next));
		return change_direction();
	}
	//return a string of what happend.
	return "";
}

std::string Actor::change_direction(){
	if(went_west){
			move_next="east";
			went_west=false;
			return get_name() + " went west";	
		} 
		else {
			move_next="west";
			went_west=true;
			return get_name() + " went east";
		}
}

std::string Actor::moving_next()const{
	return move_next;
}

void Actor::go(std::string direction) {
	//TODO
}

std::string Actor::fight(Actor* target) {
	int upper = get_attack_points() + 2;
	int lower = get_attack_points() - 2;
	int damage = rand()% (upper - lower + 1) + lower;
	target->remove_health(damage);
	std::string ret_string = get_name() + " fought " + target->get_name() + "\n";
	ret_string+= get_name() + "'s hp: " + std::to_string(get_hp()) + " " + target->get_name() + "'s hp: " + std::to_string(target->get_hp());
	if(target->get_hp() == 0) {
		ret_string+= "\n"+target->get_name() + " is dead.";
	}
	return ret_string; 
}

std::string Actor::sense()const {
	//TODO
	std::string retString = ""; 
	retString += this->get_location()->getDescription();
	auto items = this->get_location()->getItems();
	if(items.begin() != items.end()){
		retString += "\nOh look there is some random items in this env!";
		
		for(auto i = items.begin(); i!=items.end();++i){
				retString += "\n";
				retString += (*i)->getName();
		}
	}
	std::string other_actors = other_actors_in_range();
	if(other_actors != "") {
		retString += "\nThere's someone here: " + other_actors;
	}
	retString+= "\nPossible directions:" + get_location()->directions(); 
	return retString; //TODO
}

void Actor::die() {
	get_location()->remove_actor(this);
	dead = true;
}

void Actor::set_hp(int hp) {

	health = hp;
}

void Actor::increase_hp(int hp){
	int temp = get_hp() + hp; 
	if(temp > get_maxhp()){					
		health+=(get_maxhp()-get_hp());
	}
	else{
		health+=hp;
	}
					
}

void Actor::set_maxhp(int hp){
	maxhp = hp; 
}

int Actor::get_maxhp()const{
	return maxhp; 
}

void Actor::set_attack_points(int attack_points) {
	default_attack_points = attack_points;
}

int Actor::get_attack_points() const{
	return default_attack_points;
}
int Actor::get_hp() const{
	return health;
}

void Actor::set_location(Environment* location){
	get_location()->remove_actor(this);
	this->location = location;
	get_location()->add_actor(this);
}

Environment* Actor::get_location() const{
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

Actor* Actor::another_actor_in_range()const{
	std::vector<Actor*> other_actors = get_location()->get_actors(); 
	for(Actor* actor:other_actors){
		if(actor != this) {
			return actor;
		}
	}
	return NULL;

}

std::string Actor::other_actors_in_range()const{
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

bool Actor::is_dead()const{
	return dead;
}
