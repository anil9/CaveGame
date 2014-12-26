#ifndef ACTOR_H
#define ACTOR_H
#include <string>

namespace lab3{
class actor{
 public:
	actor(); 
	std::string get_type();
	void action();
	void go(std::string);
	void fight(actor&);
	std::string sense();
	void use_special();		// TODO: Should be pure virtual.
	void dead();
	int get_hp();
	void set_hp(int);
	virtual int get_attack_points();
	void set_attack_points(int);


private:
	void remove_health(int);
	std::string type;
	int health;
	int default_attack_points;


};
}

#endif