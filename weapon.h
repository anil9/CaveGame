#ifndef WEAPON_H
#define WEAPON_H
#include "wearable.h"
#include <string>

namespace lab3{
	class Weapon: public Wearable{
	public:
		Weapon(int dmg, int weight, std::string description, std::string name, std::string type);
		int get_damage();
		std::string get_effect();
		void set_effect(std::string);
		std::string get_stats() override;
	private:
		int damage;
		std::string effect;

	};	
}
#endif