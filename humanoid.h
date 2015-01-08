#ifndef HUMANOID_H
#define HUMANOID_H
#include "actor.h"
#include "wearable.h"
#include "pickup_able.h"
#include "environment.h"
#include "container.h"
#include <string>
#include <vector>

namespace lab3{
	class Humanoid: public Actor {
	public:
		Humanoid(std::string, Environment&);
		void change_gear(Wearable&);
		void talk_to(Actor&);
		void pick_up(Item*);
		std::string get_name();
		void drop(Item*);
		void set_name(std::string);
		Container& get_container();
	private:
		std::string name;
		Container mybag;
	};
}
#endif