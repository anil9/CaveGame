environment:
	g++ -Wall -g -std=c++11 environment.cpp

swamp: 
	g++ -Wall -g -std=c++11 environment.cpp outdoors.cpp swamp.cpp 
item:
	g++ -Wall -g -std=c++11 item.cpp
