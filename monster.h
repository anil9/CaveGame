#ifndef MONSTER_H
#define MONSTER_H
#include "actor.h"
#include <string>

namespace lab3 {

class Monster: public Actor{

public:
	Monster(std::string);
	std::string make_noice();


private:
std::string noice;

};

}
#endif