#include "../include/Ball.hpp"

void Ball::tick()
{
	int projected_pos_x = pos_x + speed_x;
	int projected_pos_y = pos_y + speed_y;
	if (projected_pos_x < 0)
	{
		speed_x = -speed_x;
	}
	else if (projected_pos_x > 320) // different case because points will be a thing soon
	{
		speed_x = -speed_x;
	}
	if (projected_pos_y < 0 || projected_pos_y > 200)
	{
		speed_y = -speed_y;
	}
	pos_x += speed_x;
	pos_y += speed_y;
}

void Ball::draw()
{
	set_pixel(pos_x, pos_y, color);
	set_pixel(pos_x + 1, pos_y + 1, color);
	set_pixel(pos_x + 1, pos_y, color);
	set_pixel(pos_x, pos_y + 1, color);
}