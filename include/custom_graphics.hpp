#ifndef CUSTOM_GRAPHICS_HPP
#define CUSTOM_GRAPHICS_HPP
#include <stdlib.h>

#define VGA256 0x13
#define TEXT_MODE 0x03
#define SCREEN_RAM_START 0xA0000000L
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200
#define SCREEN_SIZE 320 * 200

void set_mode(int mode);

void memset_far(void __far *ptr, char b, size_t size);

void fill_screen(char pixel_color);

void set_pixel(int x, int y, char pixel_color);

template <typename T>
void swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}
void draw_line(int start_x, int start_y, int end_x, int end_y, char pixel_color);

#endif