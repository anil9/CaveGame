#ifndef UNWEARABLE_H
#define UNWEARABLE_H
#include "pickup_able.h"
#include "obstacle.h"
#include "environment.h"
#include <string>
namespace lab3{
class Unwearable: public Pickup_able{
public:
	Unwearable(std::string use_text, int weight, std::string description, std::string name);
	std::string use();
	void set_key(Obstacle* unlocks);
	bool open(Environment*);
	bool is_key()const;
	Obstacle* get_unlocking_obstacle()const;
private:
	std::string use_text;
	Obstacle* unlocks;
	bool key = false;

};
}



#endif