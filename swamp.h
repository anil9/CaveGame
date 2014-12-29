#ifndef SWAMP_H
#define SWAMP_H
#include "outdoors.h"

namespace lab3{
	class Swamp: public Outdoors{
	public:
		Swamp(bool, bool, bool, bool, std::string);
		void sink();

	private: 


	};

}

#endif