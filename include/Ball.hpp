#ifndef BALL_HPP
#define BALL_HPP

#include "custom_graphics.hpp"

class Ball
{
public:
	int pos_x;
	int pos_y;
	int speed_x;
	int speed_y;
	int color;
	Ball(int pos_x, int pos_y, int speed_x, int speed_y, int color)
		: pos_x(pos_x), pos_y(pos_y), speed_x(speed_x), speed_y(speed_y), color(color) {}

	void tick();

	void draw();
};
#endif
