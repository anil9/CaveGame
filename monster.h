#ifndef MONSTER_H
#define MONSTER_H
#include "actor.h"
#include "environment.h"
#include "humanoid.h"
#include <string>

namespace lab3 {

class Monster: public Actor{

public:
	Monster(std::string,std::string, Environment*);
	~Monster();
	std::string use_special();
	std::string fight(Humanoid*);
	std::string action();


private:
	Humanoid* humanoid_in_range()const;
	std::string noise;

};

}
#endif