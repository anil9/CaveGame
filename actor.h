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
	Actor(const std::string, Environment*);
	virtual ~Actor(); 
	std::string get_type();
	virtual std::string action();
	const std::string get_name()const;
	void go(std::string);
	virtual std::string fight(Actor*);
	std::string sense()const;
	virtual std::string use_special()=0;		// TODO: Should be pure virtual.
	void die();
	int get_hp()const;
	void set_hp(int);
	void increase_hp(int);
	void set_maxhp(int);
	int get_maxhp()const;
	virtual int get_attack_points()const;
	void set_attack_points(int);
	void set_location(Environment*);
	Environment* get_location()const;
	void remove_health(int);
	Actor* another_actor_in_range() const;
	std::string other_actors_in_range()const;
	Container& get_container();
	bool is_dead()const;
	std::string change_direction();
	std::string moving_next()const;

private:
	bool dead = false;
	std::string type="";
	int health;
	int default_attack_points;
	int maxhp; 
	Environment* location;
	bool went_west = true;
	std::string move_next = "west";
	const std::string name;
	Container bag;


};
}

#endif