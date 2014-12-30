#ifndef OUTDOORS_H
#define OUTDOORS_H
#include "environment.h"
#include <string>
#include <initializer_list>

namespace lab3{
	class Outdoors: public Environment{
	public:	
		Outdoors();
		Outdoors(std::string);
		Outdoors(std::string, std::initializer_list<std::string>); 
		std::string weather();
	
	private:
		std::vector<std::string> weather_description;

	};
}
#endif