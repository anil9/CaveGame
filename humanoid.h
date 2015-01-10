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
		Humanoid(const std::string, Environment*);
		~Humanoid();
		void change_gear(Wearable*);
		Wearable* get_equipped(std::string);
		std::string get_gear()const;
		void pick_up(Item*);
		void drop(Item*);
		const std::string get_answer()const;
		void set_answer(const std::string);
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