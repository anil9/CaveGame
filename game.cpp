#include "game.h"
#include <iostream>
#include <string>
//#include <ctype.h>
//#include <functional>
#include <algorithm>
#include <cstring>

using namespace lab3;


Game::Game(){

	Unwearable coin("I see no use of this item", 4, "Just a regular coin.");
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
	Monster demon("YOU WILL DIE HERE",demon_cave);
	
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
				std::cout << "unreal player turn:\n";
				actor->action();
			} 
			else {
				std::cout << "your turn\n";
				next_turn = false;
				while(!next_turn){
					std::string command = "";
					std::getline(std::cin, command);	// maximum number of characters
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
	std::string token =" ";
	std::vector<std::string> commands;
	while(token != ""){
		token = strtok(NULL, " ");
		commands.push_back(token);
	}

	if(commands[0] == "go"){
		real_player->set_location(*(real_player->get_location().getNeighbor(commands[1])));
	}
	else if(commands[0] == "pick" && commands[1] == "up"){
		//real_player->pick_up()
	}
	else if(commands[0] == "drop"){

	}
	else if(commands[0] == "help"){
		
	}
	else if(commands[0] == "fight"){

	}
	else if(commands[0] == "sense"){

	}
	else if(commands[0] == "use"){
		//kolla om commands[1] == "special"
	}
	
}

int main(){
	Game game;


	return 0;
}
