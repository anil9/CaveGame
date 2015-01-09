#ifndef MONSTER_H
#define MONSTER_H
#include "actor.h"
#include "environment.h"
#include "humanoid.h"
#include <string>

namespace lab3 {

class Monster: public Actor{

public:
	Monster(std::string,std::string, Environment&);
	std::string use_special();
	std::string fight(Humanoid*);
	std::string action();


private:
	Humanoid* humanoid_in_range();
	std::string noise;

};

}
#endif