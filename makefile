FLAGS = -W -g -std=c++11
environment:
	g++ $(FLAGS) environment.cpp
actor:
	g++ $(FLAGS) actor.cpp
item:
	g++ $(FLAGS) item.cpp
monster: obj_actor monster.cpp
	g++ $(FLAGS) monster.cpp actor.o
obj_actor: actor.cpp
	g++ $(FLAGS) -c actor.cpp