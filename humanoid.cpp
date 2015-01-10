#include "humanoid.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace lab3;

Humanoid::Humanoid(const std::string name, Environment* location): Actor(name,location) {
	set_attack_points(10);
	set_hp(30);
}
Humanoid::~Humanoid(){}

void Humanoid::change_gear(Wearable* wearable) {
	if(wearable->get_type() == "weapon"){
		Weapon* weapon = dynamic_cast<Weapon*>(wearable);
		if(gear.at("weapon") == NULL){
			set_attack_points(get_attack_points() + weapon->get_damage());	
		}else{
			auto to_change = gear.at("weapon");
			Weapon* wp = dynamic_cast<Weapon*>(to_change);
			Pickup_able* pp = dynamic_cast<Pickup_able*>(to_change);
			get_container().pick_up(pp);
			set_attack_points(get_attack_points()-wp->get_damage()+weapon->get_damage());
		}
		gear.at("weapon")=wearable;
	}
	else if(wearable->get_type() == "armor"){
		Armor* armor = dynamic_cast<Armor*>(wearable);
		if(gear.at("armor")==NULL){
			set_hp(get_hp() + armor->get_protection());	
		}
		else{
			auto to_change = gear.at("armor");
			Armor* ap = dynamic_cast<Armor*>(to_change);
			Pickup_able* pp = dynamic_cast<Pickup_able*>(to_change);
			get_container().pick_up(pp);
			set_hp(get_hp()-ap->get_protection()+armor->get_protection());	
		}	
		gear.at("armor")=wearable;
	}
	std::cout<<"hp is: " + std::to_string(get_hp()) + " ap is: " + std::to_string(get_attack_points())<<std::endl;
	
		
}
std::string Humanoid::get_gear()const{
	std::string ret = "";
		for(auto i = gear.begin(); i!=gear.end();++i){
			if(i->second != NULL){
				ret += i->second->getName();
				ret += i->second->get_stats();
				ret += "\n";
			}
		}
		ret += "Totalt stats: hp = ";
		ret += std::to_string(get_hp());
		ret += "  and ap = ";
		ret += std::to_string(get_attack_points());
		return ret;
	}
void Humanoid::pick_up(Item* item) {
	
	Pickup_able* pa = dynamic_cast<Pickup_able*>(item);
	if(pa != NULL && get_container().pick_up(pa)){
		get_location()->remove_item(item); 
	}
	else{
		std::cout<<"Can not pick up that item"<<std::endl;
	}

}
		
void Humanoid::drop(Item* dropping_item){	
			
	Pickup_able* pa = dynamic_cast<Pickup_able*>(dropping_item);
	Wearable* wp = dynamic_cast<Wearable*>(pa); 
	std::string type = wp->get_type();
	if(pa!=NULL && get_container().drop(pa)){
		Outdoors* outdoors = dynamic_cast<Outdoors*>(get_location()); 
		Swamp* swamp = dynamic_cast<Swamp*>(outdoors); 
			if(swamp == NULL){
				get_location()->add_item(dropping_item);
			}
	}else if(wp != NULL && gear.find(type) != gear.end()){
		auto dropping_gear = gear.find(type);
		if(type == "weapon"){	
			Weapon* weapon = dynamic_cast<Weapon*>(gear.at(type));
			if(weapon!=NULL){
				set_attack_points(get_attack_points() - weapon->get_damage());
				gear.erase(dropping_gear);
				get_location()->add_item(dropping_item);
			}
		}
		else if(type == "armor"){
			Armor* armor = dynamic_cast<Armor*>(gear.at(type));
			if(armor != NULL){
				set_hp(get_hp() - armor->get_protection());
				gear.erase(dropping_gear);
				get_location()->add_item(dropping_item);
			}
		}
	} 
	else{
		std::cout<<"You do not have that item in you bag"<<std::endl;
	}
}

const std::string Humanoid::get_answer()const{
	return answer;
}
void Humanoid::set_answer(const std::string new_answer){
	answer = new_answer;
}

std::string Humanoid::use_special() {
	if(is_buffed()){
		return "";
	}

	isbuffed = true;
	set_attack_points(get_attack_points() + 2);
	return "You are buffed with the great buff of Thais,\nincreasing your ap with 2 for 3 turns";
}

void Humanoid::increase_buff_tick(){
	if(is_buffed()){
		++buff_tick;
		if(buff_tick == 3){
			set_attack_points(get_attack_points() -2);
			isbuffed = false;
		}
	}
}

bool Humanoid::is_buffed(){
	return isbuffed;
}

Wearable* Humanoid::get_equipped(std::string name){
	for(auto i = gear.begin(); i!=gear.end();++i){
		if(i->second != NULL && i->second->getName() == name){
			return gear.at(i->second->get_type());
		}
	}
	return NULL;
}

