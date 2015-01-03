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
swamp: 
	g++ $(FLAGS) environment.cpp outdoors.cpp swamp.cpp 

indoors:
	g++ $(FLAGS) environment.cpp indoors.cpp 

game: game.cpp object_files
	g++ $(FLAGS) game.cpp actor.o humanoid.o monster.o animal.o environment.o indoors.o outdoors.o swamp.o item.o obstacle.o pickup_able.o container.o wearable.o unwearable.o weapon.o armor.o
object_files:
	g++ $(FLAGS) -c actor.cpp
	g++ $(FLAGS) -c humanoid.cpp
	g++ $(FLAGS) -c monster.cpp
	g++ $(FLAGS) -c animal.cpp
	g++ $(FLAGS) -c environment.cpp
	g++ $(FLAGS) -c indoors.cpp
	g++ $(FLAGS) -c outdoors.cpp
	g++ $(FLAGS) -c swamp.cpp
	g++ $(FLAGS) -c item.cpp
	g++ $(FLAGS) -c obstacle.cpp
	g++ $(FLAGS) -c pickup_able.cpp
	g++ $(FLAGS) -c container.cpp
	g++ $(FLAGS) -c wearable.cpp
	g++ $(FLAGS) -c unwearable.cpp
	g++ $(FLAGS) -c weapon.cpp
	g++ $(FLAGS) -c armor.cpp
clear:
	rm *.o
