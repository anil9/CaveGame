#ifndef ANIMAL_H
#define ANIMAL_H
#include "actor.h"
#include "environment.h"

namespace lab3{
	class Animal: public Actor{
	public:
		Animal(std::string, Environment*);
		void eat();
		std::string use_special();
		std::string action();

	private:



	};

}
#endif