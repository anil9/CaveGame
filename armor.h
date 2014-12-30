#ifndef ARMOR_H
#define ARMOR_H
#include "wearable.h"
#include <string>

namespace lab3{
	class Armor: public Wearable{
	public:
		Armor(int protection, int max_durability, int weight, std::description);
		int get_max_durability();
		int get_current_durability();
		void set_current_durability(int);
		int get_protection();
	private:
		int protection;
		int max_durability;	//TODO: maybe const?
		int current_durability = max_durability;
	};
}
#endif