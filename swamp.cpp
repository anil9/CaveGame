#include "swamp.h"
#include <iostream>
#include <string>

using namespace lab3; 

Swamp::Swamp(std::string _description): Outdoors(_description){}

void Swamp::sink(Actor* a){
 a->remove_health(1);
}
