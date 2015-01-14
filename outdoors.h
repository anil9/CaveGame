#ifndef OUTDOORS_H
#define OUTDOORS_H
#include "environment.h"
#include <string>
#include <vector>

namespace lab3{
	class Outdoors: public Environment{
	public:	
		Outdoors(std::string);
		Outdoors(std::string, std::vector<Item*>); 

	};
}
#endif
