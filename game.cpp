#include "game.h"
#include <iostream>
#include <string>
#include <sstream>
//#include <ctype.h>
//#include <functional>
#include <algorithm>
#include <cstring>

using namespace lab3;


Game::Game(){

	Unwearable coin("I see no use of this item", 4, "Just a regular coin.", "coin");
	Unwearable* coinp = &coin;
	Indoors my_cabin("This is my cabin");
	Outdoors forest1("The forest. If I look around I might find items.", {coinp});
	Outdoors demon_cave("The demon cave. Scary and stuff.");
	Outdoors winning_place("Goal!");

	my_cabin.setDirection("east", forest1);
	forest1.setDirection("west", my_cabin);
	forest1.setDirection("east", demon_cave);
	demon_cave.setDirection("west", forest1);
	demon_cave.setDirection("east", winning_place);
	winning_place.setDirection("west", demon_cave);

	Humanoid player("Kalle", my_cabin);
	Monster demon("Demon", "YOU WILL DIE HERE",demon_cave);
	
	actors.push_back(&demon);
	actors.push_back(&player);

	set_real_player(player);
	std::cout <<"initialized game successfully, running game.\n"; 
	run_game();
}
void Game::set_real_player(Humanoid& real_player){
	this->real_player = &real_player;	// Can use address for equivalence check.
}


void Game::run_game(){

	while(!game_finished) {
		for(Actor* actor:actors) {
			if(actor != real_player){
				std::cout << actor->get_name() + "'s turn:\n";
				std::cout << actor->action() << std::endl;

			} 
			else {
				std::cout << "your turn\n";
				next_turn = false;
				while(!next_turn){
					std::string command = "";
					std::getline(std::cin, command);
					execute_command(command);
				}
			}

		}

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
		real_player->set_location(*(real_player->get_location()->getNeighbor(commands[1])));
		next_turn = true;
	}
	else if(commands[0] == "pick" && commands[1] == "up"){

		Item* item = real_player->get_location()->getItem(commands[2]);
		if(item->isPickupable()){
			real_player->pick_up(item); 

		}else{
			std::cout << "That item is not pickupable"<< std::endl;
		}
		next_turn = true;

	}
	else if(commands[0] == "drop"){
		Item* item = real_player->get_container().get_item(commands[1]);
		real_player->drop(item);
		next_turn = true;

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
		next_turn = true;		// Shouldn't end turn, this is only for testing.
	}
	else if(commands[0] == "use"){
		//kolla om commands[1] == "special"
	}
	else if(commands[0] == "talk" && commands[1] == "to"){

	}
	else if(commands[0] == "bag"){
		std::cout<<real_player->get_container().get_items()<<std::endl;
		next_turn = true;
	}

}

int main(){
	Game game;


	return 0;
}
