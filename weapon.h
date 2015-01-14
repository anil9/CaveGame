#ifndef WEAPON_H
#define WEAPON_H
#include "wearable.h"
#include <string>

namespace lab3{
	class Weapon: public Wearable{
	public:
		Weapon(int dmg, int weight, std::string description, std::string name, std::string type);
		~Weapon();
		int get_damage()const;
		std::string get_stats()const override;
	private:
		int damage;
		std::string effect;

	};	
}
#endif