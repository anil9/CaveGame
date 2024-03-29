#ifndef WEAPON_H
#define WEAPON_H
#include "wearable.h"
#include <string>

namespace lab3{
	class Weapon: public Wearable{
	public:
		Weapon(int dmg, int weight, std::string description);
		int get_damage();
		std::string get_effect();
		void set_effect(std::string);
	private:
		int damage;
		std::string effect;

	};	
}
#endif