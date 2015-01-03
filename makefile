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
	g++ -c actor.cpp
	g++ -c humanoid.cpp
	g++ -c monster.cpp
	g++ -c animal.cpp
	g++ -c environment.cpp
	g++ -c indoors.cpp
	g++ -c outdoors.cpp
	g++ -c swamp.cpp
	g++ -c item.cpp
	g++ -c obstacle.cpp
	g++ -c pickup_able.cpp
	g++ -c container.cpp
	g++ -c wearable.cpp
	g++ -c unwearable.cpp
	g++ -c weapon.cpp
	g++ -c armor.cpp
