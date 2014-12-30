#ifndef OBSTACLE_H
#define OBSTACLE_H
namespace lab3{
	class Obstacle{
	public:
		Obstacle(bool);
		bool is_movable();

	private:
		bool movable;

	};
}
#endif