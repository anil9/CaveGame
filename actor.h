#ifndef ACTOR_H
#define ACTOR_H
#include "environment.h"
#include "unwearable.h"
#include <string>

namespace lab3{
class Actor{
 public:
	Actor(Environment&); 
	std::string get_type();
	std::string action();
	void go(std::string);
	void fight(Actor&);
	std::string sense();
	void use_special();		// TODO: Should be pure virtual.
	void dead();
	int get_hp();
	void set_hp(int);
	virtual int get_attack_points();
	void set_attack_points(int);
	void set_location(Environment&);
	Environment& get_location();
	void remove_health(int);

private:
	
	std::string type;
	int health;
	int default_attack_points;
	Environment* location;
	bool went_west = false;
	std::string move_next = "east";


};
}

#endif