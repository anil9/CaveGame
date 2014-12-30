#ifndef INDOORS_H
#define INDOORS_H
#include "environment.h"
#include <string>
#include <initializer_list>

namespace lab3{
	class Indoors: public Environment{
		Indoors(bool, bool, bool, bool, std::string);
		Indoors(bool, bool, bool, bool, std::string, std::initializer_list<std::string>);
	};
}

#endif