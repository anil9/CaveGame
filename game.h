#ifndef GAME_H
#define GAME_H
#include "actor.h"
#include "environment.h"
#include "item.h"
#include "humanoid.h"
#include "indoors.h"
#include "outdoors.h"
#include "monster.h"
#include <vector>
#include <string>

namespace lab3{

class Game{
public:
Game();



private:
	void set_real_player(Humanoid&);
	void run_game();
	void execute_command(std::string);
	Humanoid* real_player;
	bool game_finished = false;
	bool next_turn = false;


	std::vector<Actor*> actors;
	std::vector<Environment*> environments;
};
}
#endif