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
	Actor(std::string, Environment*);
	virtual ~Actor(); 
	std::string get_type();
	virtual std::string action();
	std::string get_name();
	void go(std::string);
	virtual std::string fight(Actor*);
	std::string sense();
	virtual std::string use_special()=0;		// TODO: Should be pure virtual.
	void die();
	int get_hp();
	void set_hp(int);
	void increase_hp(int);
	virtual int get_attack_points();
	void set_attack_points(int);
	void set_location(Environment*);
	Environment* get_location();
	void remove_health(int);
	Actor* another_actor_in_range();
	std::string other_actors_in_range();
	Container& get_container();
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