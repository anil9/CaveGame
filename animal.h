#ifndef ANIMAL_H
#define ANIMAL_H
#include "actor.h"
#include "environment.h"

namespace lab3{
	class Animal: public Actor{
	public:
		Animal(Environment&);
		void eat();

	private:



	};

}
#endif