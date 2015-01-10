#ifndef HUMANOID_H
#define HUMANOID_H
#include "actor.h"
#include "wearable.h"
#include "pickup_able.h"
#include "environment.h"
#include "outdoors.h"
#include "swamp.h"
#include "weapon.h"
#include "armor.h"
#include <string>
#include <vector>
#include <map>

namespace lab3{
	class Humanoid: public Actor {
	public:
		Humanoid(std::string, Environment*);
		~Humanoid();
		void change_gear(Wearable*);
		std::string get_gear();
		Wearable* get_equipped(std::string);
		void pick_up(Item*);
		void drop(Item*);
		std::string get_answer();
		void set_answer(std::string);
		std::string use_special();
		void increase_buff_tick();
		bool is_buffed();

	private:
		bool isbuffed = false; 
		int buff_tick = 0; 
		std::string answer = "";
		std::map<std::string,Wearable*> gear = {{"armor", NULL},{"weapon", NULL}}; 
	};
}
#endif