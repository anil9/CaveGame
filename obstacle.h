#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "environment.h"
#include "unwearable.h"
#include <string>
namespace lab3{
	class Obstacle: public Environment{
	public:
		Obstacle(std::string,std::string, Unwearable*);
		bool is_locked()const;
		void set_backtrack_direction(std::string direction, Environment* neighbor);
		void setDirection(std::string, Environment*);
		void unlock();
		Unwearable* get_key();
		std::string getDescription()const;


	private:
		bool locked = true;
		std::map<std::string, Environment*> hidden_neighbors;
		Unwearable* key;
		std::string locked_description;

	};
}
#endif