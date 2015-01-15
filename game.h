#ifndef GAME_H
#define GAME_H
#include "actor.h"
#include "environment.h"
#include "item.h"
#include "humanoid.h"
#include "indoors.h"
#include "outdoors.h"
#include "swamp.h"
#include "monster.h"
#include "unwearable.h"
#include "wearable.h"
#include "weapon.h"
#include "animal.h"
#include "obstacle.h"
#include <vector>
#include <string>

namespace lab3{

class Game{
public:
Game();



private:
	void set_real_player(Humanoid *);
	void run_game();
	void execute_command(std::string);
	std::string get_adventure_intro()const;
	void remove_dead(const std::vector<Actor*>&);
	void swamp_sink(Actor*);
	bool real_player_close(const Actor*);
	void you_lost();
	void you_won();

	Humanoid* real_player;
	bool game_finished = false;
	bool next_turn = false;
	std::vector<Actor*> actors;
	std::vector<Environment*> environments;
};
}
#endif