#ifndef CONTAINER_H
#define CONTAINER_H
#include "pickup_able.h"
#include <string>
#include <vector>


using namespace lab3{
	class Container: Pickup_able{
	public:
		Container(int capacity, int weight, std::string description);
		vector<Pickup_able*> containing();
		drop(Pickup_able&);

	private:
		vector<Pickup_able*> contains;


	};
}