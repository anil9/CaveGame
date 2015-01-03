#ifndef CONTAINER_H
#define CONTAINER_H
#include "pickup_able.h"
#include <string>
#include <vector>


 namespace lab3{
	class Container: Pickup_able{
	public:
		Container(int capacity, int weight, std::string description);
		std::vector<Pickup_able*> containing();
		void drop(Pickup_able&);

	private:
		std::vector<Pickup_able*> contains;
		int capacity;

	};
}
#endif