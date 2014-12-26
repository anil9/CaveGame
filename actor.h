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
	void fight(actor);
	std::string sense();
	void use_special();

private:
std::string type;


};
}

#endif