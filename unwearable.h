#ifndef UNWEARABLE_H
#define UNWEARABLE_H
#include "pickup_able.h"
#include <string>
namespace lab3{
class Unwearable: public Pickup_able{
public:
	Unwearable(std::string use_text, int weight, std::string description);
	std::string use();
private:
	use_text;

};
}



#endif