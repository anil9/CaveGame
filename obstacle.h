#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "item.h"
#include <string>
namespace lab3{
	class Obstacle: public Item{
	public:
		Obstacle(bool, std::string);
		bool is_movable();

	private:
		bool movable;

	};
}
#endif