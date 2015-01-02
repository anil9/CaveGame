#ifndef GAME_H
#define GAME_H
#include "actor.h"
#include "environment.h"
#include "item.h"
#include "humanoid.h"
#include <vector>
#include <string>

namespace lab3{

class Game{
public:
Game();



private:
	set_real_player(lab3::Humanoid&);
	run();
	execute_command(std::string)
	Humanoid* real_player;
	bool game_finished = false;
	bool next_turn = false;


	vector<Actor*> actors;
	vector<Environment*> environments;
};
}
#endif