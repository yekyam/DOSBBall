#include <stdio.h>
#include <stdlib.h>

#include "dos.h"
#include "include/Ball.hpp"
#include "include/custom_graphics.hpp"
#include "include/ScreenModeManager.hpp"

int main()
{
	ScreenModeManager m(VGA256, TEXT_MODE);
	fill_screen(4);
	// draw_line(0, 0, 320, 150, 1);
	size_t ticks;
	Ball b(100, 100, 10, 10, 15);
	while (!kbhit())
	{
		fill_screen(4);
		b.tick();
		b.draw();
	}
}
