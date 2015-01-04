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
		std::string weather();
	
	private:
		const std::vector<std::string> weather_description = {"Det regnar", "Det snöar", "Vinden piskar", "Åskan mullrar", "Helt lugnt väder"};

	};
}
#endif
