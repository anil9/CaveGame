#ifndef ACTOR_H
#define ACTOR_H
#include "environment.h"
#include "item.h"
#include "container.h"
#include <string>

namespace lab3{
	class Environment;
class Actor{
 public:
	Actor(std::string, Environment&); 
	std::string get_type();
	std::string action();
	std::string get_name();
	void go(std::string);
	virtual std::string fight(Actor*);
	std::string sense();
	void use_special();		// TODO: Should be pure virtual.
	void die();
	int get_hp();
	void set_hp(int);
	virtual int get_attack_points();
	void set_attack_points(int);
	void set_location(Environment&);
	Environment* get_location();
	void remove_health(int);
	Actor* another_actor_in_range();
	Container& get_container();
	void set_container(Pickup_able*);
	bool is_dead();

private:
	bool dead = false;
	std::string type="";
	int health;
	int default_attack_points;
	Environment* location;
	bool went_west = true;
	std::string move_next = "west";
	std::string name;
	Container bag;


};
}

#endif