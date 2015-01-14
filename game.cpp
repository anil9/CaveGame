#include "game.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cstring>
#include <exception>
#include <thread>
#include <chrono>

using namespace lab3;


Game::Game(){

	//Setup items
	Unwearable coin("I see no use of this item", 4, "Just a regular coin.", "coin");
	Weapon axe(2, 10, "The great axe of the demon", "demonslayer", "weapon");
	Weapon knife(2, 10, "Just a simple knife", "knify", "weapon");
	Weapon sensei(4, 5, "Samuraisword", "sensei", "weapon");
	Weapon sword(3, 10, "A pretty good sword", "Swordy", "weapon");
	Armor armor(2, 10, "Good armor", "armor", "armor");
	Armor golden(10, 10, "Golden armor", "golden armor", "armor");
	Unwearable tooth("Eeeeuwh its a smelly tooth", 1, "Just a old tooth.", "demontooth");
	Unwearable candle("There will be light", 1, "romantic candle", "candle");
	Unwearable hp_pot("Ahh.. I feel much better now", 1, "potion", "potion");
	hp_pot.set_hp_pot(10);
	Unwearable hp_pot2("Ahh.. I feel much better now", 1, "potion", "potion");
	hp_pot2.set_hp_pot(10);
	//Setup environment
	Indoors my_cabin("This is my cabin", {&knife, &sword, &armor, &candle, &hp_pot2});
	Outdoors forest1("The forest. If I look around I might find items.", {&coin});
	Indoors demon_cave("The demon cave. Scary and stuff.", {&hp_pot});
	Outdoors winning_place("Hoccar's cave");
	Swamp swamp("Euuhw smelly mud everywhere!");
	Obstacle locked_area("This place is locked. Try to unlock it with a coin","Quick way to goal!");
	Obstacle dark_cave("This is a dark cave, maybe if you have anything to light up?", "Oh look the cave is bigger!");
	Indoors cave("random cave");

	my_cabin.setDirection("east", &forest1);
	forest1.setDirection("west", &my_cabin);
	forest1.setDirection("east", &demon_cave);
	forest1.setDirection("south", &swamp);
	forest1.setDirection("north", &dark_cave);
	swamp.setDirection("north", &forest1);
	demon_cave.setDirection("west", &forest1);
	demon_cave.setDirection("east", &winning_place);
	winning_place.setDirection("west", &demon_cave);
	locked_area.set_backtrack_direction("west",&swamp);
	locked_area.setDirection("east", &winning_place);
	dark_cave.set_backtrack_direction("south", &forest1);
	dark_cave.setDirection("north", &cave);
	swamp.setDirection("east", &locked_area);
	cave.setDirection("south", &dark_cave);

	coin.set_key(&locked_area);
	candle.set_key(&dark_cave);

	//Setup actors
	Humanoid player("Kalle", &my_cabin);
	Monster demon("Demon", "YOU WILL DIE HERE",&demon_cave);
	Monster hoccar("Hoccar", "I'm the Lord of Demons!", &winning_place);
	hoccar.set_hp(50);
	hoccar.set_attack_points(12);
	demon.get_container().pick_up(&axe);
	demon.get_container().pick_up(&tooth);
	Humanoid inkeeper("inkeeper", &my_cabin);
	Humanoid troll("sleepytroll", &cave);
	inkeeper.set_answer("Hello and welcome to my humble cabin! -Please help yourself to the items in here that you want!-Good luck");
	troll.set_answer("ZzZz... uhm.. arg..what..is there someone here?!-Take this *throws something on the cold cavefloor*!");
	troll.get_container().pick_up(&sensei);
	Animal rabbit("Rabbit", &forest1);
	Animal moose("Moose", &forest1);
	moose.set_hp(35);
	moose.set_attack_points(7);
	Animal lion("Lion", &forest1);
	lion.set_attack_points(10);
	Animal turtle("Turtle", &forest1);
	turtle.set_hp(45);
	turtle.get_container().pick_up(&golden);


	actors.push_back(&demon);
	actors.push_back(&player);
	actors.push_back(&rabbit);
	actors.push_back(&moose);
	actors.push_back(&lion);
	actors.push_back(&turtle);
	actors.push_back(&hoccar); // Ska inte kunna gå fram och tillbaka.


	set_real_player(&player);
	std::cout <<"initialized game successfully, running game.\n"; 
	std::cout<<get_adventure_intro()<<std::endl;
	run_game();
}
void Game::set_real_player(Humanoid* real_player){
	this->real_player = real_player;	// Can use address for equivalence check.
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
		srand(time(0));
		for(Actor* actor:actors) {

			swamp_sink(actor);
			
			if(actor->is_dead()){
				auto loot = actor->get_container().containing();
				int num_of_loots = loot.size();
				if(num_of_loots!=0){
					int i = rand()% num_of_loots+1;
					auto item = loot.at(i-1);
					actor->get_container().drop(item);
					actor->get_location()->add_item(item);
				}
				if (actor == real_player){
					you_lost();
					break;
				} else if(actor->get_name() == "Hoccar"){
					you_won();
					break;
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
				real_player->increase_buff_tick();
			}
		}
			remove_dead(dead_list);

	}
}

void Game::execute_command(std::string command){
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
			real_player->set_location(neighbor);
			next_turn = true;
		} 
		else {
			std::cout << "You can't go that way! Type sense for possible directions.\n";
		}
	}
	else if(commands[0] == "pick" && commands[1] == "up"){
		if(commands.size()> 2){
			Item* item = real_player->get_location()->getItem(commands[2]);
			if(item != NULL && item->isPickupable()){
				real_player->pick_up(item); 

			}
		}else{
				std::cout << "That item is not pickupable"<< std::endl;
		}
			next_turn = true;

	}
	else if(commands[0] == "drop"){
		Item* item = real_player->get_container().get_item(commands[1]);
		if(item == NULL){
			item = real_player->get_equipped(commands[1]);
		}
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
		std::cout<<"===================="<<std::endl;
		std::cout << "These are the following commands that you can use,\ngo direction\npick up itemname\ndrop itemname\nhelp\nsense\nuse special (or) itemname\nfight actorname\ntalk to actorname\nequip itemname\nshow bag (or) gear" << std::endl;
		std::cout<<"===================="<<std::endl;
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
		if(commands.size()>1){
			if(commands[1] == "special"){
				std::string special = real_player->use_special();
				if(special == ""){
					std::cout<<"You can't renew your buff"<<std::endl;
				}else{
					std::cout<<special<<std::endl;
				}
			}
			else if(real_player->get_container().get_item(commands[1]) != NULL){
				auto use_able = real_player->get_container().get_item(commands[1]);
				Unwearable* item = dynamic_cast<Unwearable*>(use_able);
				if(item != NULL){
					if(item->is_key()) {
						if(item->open(real_player->get_location())){
							std::cout << item->getName() << ": "<< item->use() << ".\n";
							std::cout << item->getName() << ": Whoa! Something happend.\n";
						} 
						else {
							std::cout << item->getName() << ": "<< item->use() << ".\n";
						}
					}
					else if(item->is_hp_pot()){
						int increased = real_player->get_maxhp()- real_player->get_hp();
						real_player->increase_hp(item->get_hp_pot());
						
						if(increased > item->get_hp_pot()){
							increased = item->get_hp_pot();
						}
						std::cout << item->getName() << ": "<< item->use() << ".\n";
						std::cout << "Hp increased by " << increased << "\n";
						std::cout <<  item->getName() << " used.\n";
						
						real_player->get_container().drop(item); //Potion erased;



					}
					else {
						// useable unwearable item
						std::cout << item->getName() << ": "<< item->use() << ".\n";
					}
				}
				else {
					//useable pickup-able item
					//don't have any of those yet.
					std::cout << "You can't use that.\n";
				}
			} 
			else {
				std::cout << "You don't have that item in your bag.\n";
			}
		}
		else{
			std::cout<<"What to use?"<<std::endl;
		}
	}
	else if(commands[0] == "talk" && commands[1] == "to"){
			if(commands.size()>2){
				Humanoid* talk_to = dynamic_cast<Humanoid*>(real_player->get_location()->get_actor(commands[2]));
				if(talk_to == NULL){
					std::cout<<"Can not talk to that actor"<<std::endl;
				}else{
					std::string temp = talk_to->get_answer();
					for(char c: temp){
						std::this_thread::sleep_for(std::chrono::milliseconds(50));
						if(c == '-'){
							std::cout<<"\n";
						}
						std::cout<<c<<std::flush;
					}
					std::cout<<"\n";
					//std::cout<<talk_to->get_answer()<<std::endl;
					if(talk_to->get_name() == "sleepytroll"){
						auto loot = talk_to->get_container().containing();
						auto give_item = loot.at(0);
						talk_to->get_container().drop(give_item);
						talk_to->get_location()->add_item(give_item);
					}
					next_turn = true;
				}
			}
				
	}
	else if(commands[0] == "equip"){
		auto item = real_player->get_container().get_item(commands[1]);
		if(item!=NULL){
			Wearable* gear_item = dynamic_cast<Wearable*>(item); 
			real_player->change_gear(gear_item);
			real_player->get_container().drop(gear_item);
		}
	}
	else if(commands[0] == "show"){
		if(commands[1] == "bag"){
			std::cout<<real_player->get_container().get_items()<<std::endl;
		}else if(commands[1] == "gear"){
			std::cout<<real_player->get_gear()<<std::endl;
			if(real_player->is_buffed()){
				std::cout<<"Buff: Great buff of Thais"<<std::endl;
			}
		}
	}
	else if(commands[0] == "quit"){
		game_finished = true;
		next_turn = true;	
	}	
	else{
		std::cout<<"That is not a command, try again!"<<std::endl;
	}

}

std::string Game::get_adventure_intro()const{
	std::string intro = "";
	intro += "############################################################\n";
	intro += "#         Welcome to the world of Thargon,                 #\n";
	intro += "#       You are an elf named Theoden from Thais,           #\n";
	intro += "#   your objective is to defeat the Lord of Demons Hoccar, #\n";
	intro += "#     to free all elves from the demons slavery.           #\n";
    intro += "#                                                          #\n";
	intro += "#    You have been transported to the inkeepers cabin,     #\n";
	intro += "#         to armor up and start your adventure,            #\n";
	intro += "#      Good luck and may the gods of Thargon be with you.  #\n";
	intro += "############################################################\n";
	return intro;
}
void Game::remove_dead(const std::vector<Actor*>& dead_list){
	if(dead_list.size() > 0){
		for(Actor* actor: dead_list){
			actors.erase(std::find(actors.begin(), actors.end(), actor));
		}
	}
}

bool Game::real_player_close(const Actor* actor){
	return actor->get_location() == real_player->get_location();
}

void Game::you_lost(){
	game_finished = true;
	std::string outro="";
	outro += "######################################################\n";
	outro += "#   The world of Thargon continues without Theoden.  #\n";
	outro += "#         All the elves will live in slavery         #\n";
	outro += "#            for yet another eternity.               #\n";
	outro += "#               Thanks for playing!                  #\n";
	outro += "######################################################\n";
	std::cout << outro << std::endl;
}

void Game::you_won(){
	game_finished = true;
	std::string outro="";
	outro += "######################################################\n";
	outro += "#             You have done it! You won!             #\n";
	outro += "#     The demons are weak now when Hoccar is gone.   #\n";
	outro += "#          It'll be an easy task to clear out        #\n";
	outro += "#                  the rest of them.                 #\n";
	outro += "#                 Thanks for playing!                 #\n";
	outro += "######################################################\n";
	std::cout << outro << std::endl;
}

int main(){
	Game game;


	return 0;
}
