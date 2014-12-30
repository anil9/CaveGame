#ifndef INDOORS_H
#define INDOORS_H
#include "environment.h"
#include <string>
#include <initializer_list>

namespace lab3{
	class Indoors: public Environment{
		Indoors(std::string);
		Indoors(std::string, std::initializer_list<std::string>);
	};
}

#endif