#ifndef ARMOR_H
#define ARMOR_H
#include "wearable.h"
#include <string>

namespace lab3{
	class Armor: public Wearable{
	public:
		Armor(int protection, int max_durability, int weight, std::string description, std::string name, std::string type);
		int get_max_durability()const;
		int get_current_durability()const;
		void set_current_durability(int);
		int get_protection()const;
		std::string get_stats()const override;
	private:
		int protection;
		int max_durability;	//TODO: maybe const?
		int current_durability = max_durability;
	};
}
#endif