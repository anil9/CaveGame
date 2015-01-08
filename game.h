#ifndef GAME_H
#define GAME_H
#include "actor.h"
#include "environment.h"
#include "item.h"
#include "humanoid.h"
#include "indoors.h"
#include "outdoors.h"
#include "monster.h"
#include "unwearable.h"
#include "weapon.h"
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
	std::string get_adventure_intro();
	Humanoid* real_player;
	bool game_finished = false;
	bool next_turn = false;
	void remove_dead(std::vector<Actor*>&);

	std::vector<Actor*> actors;
	std::vector<Environment*> environments;
};
}
#endif