#ifndef CONTAINER_H
#define CONTAINER_H
#include "pickup_able.h"
#include <string>
#include <vector>


 namespace lab3{
	class Container: public Item{
	public:
		Container(int capacity);
		std::vector<Pickup_able*> containing();
		bool drop(Pickup_able*);
		bool pick_up(Pickup_able*);
		Pickup_able* get_item(std::string);
		std::string get_items();

	private:
		std::vector<Pickup_able*> contains;
		int capacity;
		int used = 0;

	};
}
#endif