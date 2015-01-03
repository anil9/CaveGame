#ifndef HUMANOID_H
#define HUMANOID_H
#include "actor.h"
#include "wearable.h"
#include "pickup_able.h"
#include "environment.h"
#include <string>
#include <vector>

namespace lab3{

	class Humanoid: public Actor {
	public:
		Humanoid(std::string, Environment&);
		void change_gear(Wearable&);
		void talk_to(Actor&);
		void pick_up(Pickup_able&);
		std::string get_name();
		void drop(Pickup_able&);
		void set_name(std::string);

	private:
		std::vector<Pickup_able*> possessions;
		std::string name;
	};
}
#endif