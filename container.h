#ifndef CONTAINER_H
#define CONTAINER_H
#include "pickup_able.h"
#include <string>
#include <vector>


 namespace lab3{
	class Container: public Item{
	public:
		Container(int capacity);
		~Container();
		std::vector<Pickup_able*> containing()const;
		bool drop(Pickup_able*);
		bool pick_up(Pickup_able*);
		Pickup_able* get_item(std::string)const;
		std::string get_items()const;

	private:
		std::vector<Pickup_able*> contains;
		int capacity;
		int used = 0;

	};
}
#endif