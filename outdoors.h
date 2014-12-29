#ifndef OUTDOORS_H
#define OUTDOORS_H
#include "environment.h"
#include <string>

namespace lab3{
	class Outdoors: public Environment{
	public:	
		Outdoors(); 
		std::string weather();
	
	private:
		std::vector<std::string> weather_description;

	};
}
#endif