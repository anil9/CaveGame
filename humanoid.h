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
		Humanoid(std::string, Environment&);
		void change_gear(Wearable*);
		std::string get_gear();
		void pick_up(Item*);
		void drop(Item*);
		std::string get_answer();
		void set_answer(std::string);

	private:
		//Container mybag;
		std::string answer = "";
		std::map<std::string,Wearable*> gear = {{"armor", NULL},{"weapon", NULL}}; 
	};
}
#endif