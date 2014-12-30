#include "indoors.h"
#include <string>
#include <initializer_list>

using namespace lab3;

Indoors::Indoors(std::string _description){
	env_description = _description;

}


Indoors::Indoors(std::string _description, std::initializer_list<std::string> items){
	env_description = _description;
	items_in_env = items; 
}

int main(){

	return 1;
}