#ifndef SWAMP_H
#define SWAMP_H
#include "outdoors.h"
#include "actor.h"

namespace lab3{
	class Swamp: public Outdoors{
	public:
		Swamp(std::string);
		void sink(Actor*);

	private: 


	};

}

#endif