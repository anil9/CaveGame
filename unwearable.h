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
	~Unwearable();
	std::string use();
	void set_key(Obstacle* unlocks);
	bool open(Environment*);
	bool is_key()const;
	Obstacle* get_unlocking_obstacle()const;
	void set_hp_pot(int);
	bool is_hp_pot();
	int get_hp_pot();
private:
	std::string use_text;
	Obstacle* unlocks;
	bool key = false;
	bool hp_pot = false;
	int healing_amount=0;

};
}



#endif