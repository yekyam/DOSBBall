#include "../include/custom_graphics.hpp"

void set_mode(int mode)
{
	asm mov AH, 0;
	asm mov AL, mode;
	asm int 10h;
}

void memset_far(void __far *ptr, char b, size_t size)
{
	char __far *cpy = (char __far *)ptr;
	for (int i = 0; i < size; i++)
	{
		*cpy = b;
		cpy += 1;
	}
}

void fill_screen(char pixel_color)
{
	memset_far((void __far *)SCREEN_RAM_START, pixel_color, SCREEN_SIZE);
}

void set_pixel(int x, int y, char pixel_color)
{
	unsigned char __far *ptr = (unsigned char __far *)SCREEN_RAM_START;
	ptr[(y * SCREEN_WIDTH) + x] = pixel_color;
}

void draw_line(int start_x, int start_y, int end_x, int end_y, char pixel_color)
{
	if (start_x == end_x && start_y == end_y)
	{
		set_pixel(start_x, start_y, pixel_color);
	}
	else if (start_y == end_y)
	{
		if (start_x > end_x)
		{
			swap(start_x, end_x);
		}
		unsigned char __far *ptr = (unsigned char __far *)SCREEN_RAM_START;
		for (int i = start_x; i < end_x; i++)
		{
			ptr[start_y * SCREEN_WIDTH + i] = pixel_color;
		}
	}
	else if (start_x == end_x)
	{
		if (start_y > end_y)
		{
			swap(start_y, end_y);
		}
		for (int i = start_y; i <= end_y; i++)
		{
			set_pixel(start_x, i, pixel_color);
		}
	}
	else
	{
		if (start_x > end_x)
		{
			swap(start_x, end_x);
			swap(start_y, end_y);
		}
		float slope = ((float)end_y - (float)start_y) / ((float)end_x - (float)start_x);
		float y_int = (float)start_y - (slope * (float)start_x);
		for (int i = start_x; i <= end_x; i++)
		{
			int y = ((float)i * slope) + y_int;
			set_pixel(i, (int)y, pixel_color);
		}
	}
}
