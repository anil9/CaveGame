#ifndef WEARABLE_H
#define WEARABLE_H
#include "pickup_able.h"
#include <string>

namespace lab3{
	class Wearable: public Pickup_able{
	public:
		Wearable(int weight, std::string description);
		void wear();
		void unwear();
	private:

	};
}
#endif