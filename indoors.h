#ifndef INDOORS_H
#define INDOORS_H
#include "environment.h"
#include <string>
#include <vector>

namespace lab3{
	class Indoors: public Environment{
	public:
		Indoors(std::string);
		Indoors(std::string, std::vector<Item*>);
	private:
	};
}

#endif