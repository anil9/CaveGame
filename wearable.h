#ifndef WEARABLE_H
#define WEARABLE_H
#include "pickup_able.h"
#include <string>

namespace lab3{
	class Wearable: public Pickup_able{
	public:
		Wearable(int weight, std::string description, std::string names, std::string type);
		std::string get_type();
		virtual std::string get_stats();
	private:
		std::string type;
	};
}
#endif