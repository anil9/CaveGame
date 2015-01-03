#ifndef MONSTER_H
#define MONSTER_H
#include "actor.h"
#include "environment.h"
#include <string>

namespace lab3 {

class Monster: public Actor{

public:
	Monster(std::string, Environment&);
	std::string make_noise();


private:
std::string noise;

};

}
#endif