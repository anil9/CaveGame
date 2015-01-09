#include "game.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cstring>
#include <exception>

using namespace lab3;


Game::Game(){

	//Setup items
	Unwearable coin("I see no use of this item", 4, "Just a regular coin.", "coin");
	Unwearable* coinp = &coin;
	Weapon axe(2, 10, "The great axe of the demon", "demonslayer", "weapon");
	Weapon* axep = &axe;
	Weapon knife(2, 10, "Just a simple knife", "knify", "weapon");
	Weapon* knifep = &knife;
	Weapon sword(3, 10, "A pretty good sword", "Swordy", "weapon");
	Weapon* swordp = &sword;
	Unwearable tooth("Eeeeuwh its a smelly tooth", 1, "Just a old tooth.", "demontooth");
	Unwearable* toothp = &tooth;
	//Setup environment
	Indoors my_cabin("This is my cabin", {knifep, swordp});
	Outdoors forest1("The forest. If I look around I might find items.", {coinp});
	Outdoors demon_cave("The demon cave. Scary and stuff.");
	Outdoors winning_place("Goal!");
	Swamp swamp("Euuhw smelly mud everywhere!");

	my_cabin.setDirection("east", forest1);
	forest1.setDirection("west", my_cabin);
	forest1.setDirection("east", demon_cave);
	forest1.setDirection("south", swamp);
	swamp.setDirection("north", forest1);
	demon_cave.setDirection("west", forest1);
	demon_cave.setDirection("east", winning_place);
	winning_place.setDirection("west", demon_cave);

	//Setup actors
	Humanoid player("Kalle", my_cabin);
	Monster demon("Demon", "YOU WILL DIE HERE",demon_cave);
	demon.get_container().pick_up(axep);
	demon.get_container().pick_up(toothp);
	Humanoid inkeeper("inkeeper", my_cabin);
	inkeeper.set_answer("Hello and welcome to my humble cabin! \nPlease help yourself to the items in here that you want!\n Good luck");
	Animal rabbit("Rabbit", forest1);
	Animal moose("Moose", forest1);
	moose.set_hp(35);
	moose.set_attack_points(7);
	Animal lion("Lion", forest1);
	lion.set_attack_points(10);
	Animal turtle("Turtle", forest1);
	turtle.set_hp(45);


	actors.push_back(&demon);
	actors.push_back(&player);
	actors.push_back(&rabbit);
	actors.push_back(&moose);
	actors.push_back(&lion);
	actors.push_back(&turtle);


	set_real_player(player);
	std::cout <<"initialized game successfully, running game.\n"; 
	std::cout<<get_adventure_intro()<<std::endl;
	run_game();
}
void Game::set_real_player(Humanoid& real_player){
	this->real_player = &real_player;	// Can use address for equivalence check.
}

void Game::swamp_sink(Actor* actor){
	Outdoors* outdoors = dynamic_cast<Outdoors*>(actor->get_location());
			Swamp* swamp = dynamic_cast<Swamp*>(outdoors);
			if(swamp != NULL){
				swamp->sink(actor);
				std::cout<<actor->get_name() + " loosing health while sinking in the swamp"<<std::endl;
			}
}


void Game::run_game(){

	while(!game_finished) {
		std::vector<Actor*> dead_list;
		for(Actor* actor:actors) {

			swamp_sink(actor);
			
			if(actor->is_dead()){
				auto loot = actor->get_container().containing();
				int num_of_loots = loot.size();
				if(num_of_loots!=0){
					srand(time(NULL));
					int i = rand()% num_of_loots+1;
					auto item = loot.at(i-1);
					actor->get_container().drop(item);
					actor->get_location()->add_item(item);
				}
				dead_list.push_back(actor);
				continue;

			}
			if(actor != real_player){
				if(real_player_close(actor)){
					std::cout << actor->get_name() + "'s turn:\n";
					std::cout << actor->action() + "\n\n";
				} 
				else {
					actor->action();
				}

			} 
			else {
				std::cout << "===============\n";
				std::cout << "your turn\n";
				next_turn = false;
				while(!next_turn){
					std::string command = "";
					std::getline(std::cin, command);
					execute_command(command);
				}
				std::cout << "===============\n";
			}
		}
			remove_dead(dead_list);

	}
}

void Game::execute_command(std::string command){
	//TODO
	// if command should end the player's turn set next_turn = true.
	std::transform(command.begin(), command.end(), command.begin(), ::tolower);
	
	std::vector<std::string> commands;
	
	std::stringstream ss(command);
	std::string s;

	while(getline(ss, s, ' ')){
		commands.push_back(s);
	}

	if(commands[0] == "go"){
		Environment* neighbor = real_player->get_location()->getNeighbor(commands[1]);
		if(neighbor != NULL){
			real_player->set_location(*(neighbor));
			next_turn = true;
		} 
		else {
			std::cout << "You can't go that way! Type sense for possible directions.\n";
		}
	}
	else if(commands[0] == "pick" && commands[1] == "up"){

		Item* item = real_player->get_location()->getItem(commands[2]);
		if(item != NULL && item->isPickupable()){
			real_player->pick_up(item); 

		}else{
			std::cout << "That item is not pickupable"<< std::endl;
		}
		next_turn = true;

	}
	else if(commands[0] == "drop"){
		Item* item = real_player->get_container().get_item(commands[1]);
		if(item != NULL){
			real_player->drop(item);
			std::cout << "You dropped " << commands[1]<< "\n";
			next_turn = true;
		} 
		else {
			std::cout << "You don't have that item.\n";	
		}

	}
	else if(commands[0] == "help"){
		std::cout << "Vilka kommandon man kan använda som spelare" << std::endl;
	}
	else if(commands[0] == "fight"){
		Actor* target = real_player->get_location()->get_actor(commands[1]);
		if(target != NULL){
			
			std::cout << real_player->fight(target) << "\n";
			next_turn = true; 
		} else {
			std::cout << "You can't fight that target\n";
		}

	}
	else if(commands[0] == "sense"){
		std::cout<< real_player->sense() << std::endl;
		//next_turn = true;		// Shouldn't end turn, this is only for testing.
	}
	else if(commands[0] == "use"){
		//kolla om commands[1] == "special"
	}
	else if(commands[0] == "talk" && commands[1] == "to"){
			Humanoid* talk_to = dynamic_cast<Humanoid*>(real_player->get_location()->get_actor(commands[2]));
			if(talk_to == NULL){
				std::cout<<"Can not talk to that actor"<<std::endl;
			}else{
			std::cout<<talk_to->get_answer()<<std::endl;
			}
			next_turn = true;
	}
	else if(commands[0] == "equip"){
		auto item = real_player->get_container().get_item(commands[1]);
		if(item!=NULL){
			Wearable* gear_item = dynamic_cast<Wearable*>(item); 
			real_player->change_gear(gear_item);
			real_player->get_container().drop(item);
		}
	}
	else if(commands[0] == "show"){
		if(commands[1] == "bag"){
			std::cout<<real_player->get_container().get_items()<<std::endl;
		}else if(commands[1] == "gear"){
			std::cout<<real_player->get_gear()<<std::endl;
		}
	}	
	else{
		std::cout<<"That is not a command, try again!"<<std::endl;
	}

}

std::string Game::get_adventure_intro(){
	std::string intro = "";
	intro += "################################################\n";
	intro += "#         Our game intro                       #\n";
	intro += "#         You are an Elf LOL                   #\n";
	intro += "#  Kill the Demon and be nice to the inkeeper! #\n";
	intro += "################################################\n";
	return intro;
}
void Game::remove_dead(std::vector<Actor*>& dead_list){
	if(dead_list.size() > 0){
		for(Actor* actor: dead_list){
			actors.erase(std::find(actors.begin(), actors.end(), actor));
		}
	}
}

bool Game::real_player_close(Actor* actor){
	return actor->get_location() == real_player->get_location();
}

int main(){
	Game game;


	return 0;
}
