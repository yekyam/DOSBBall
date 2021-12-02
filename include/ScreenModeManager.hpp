#ifndef SCREENMODEMANAGER_HPP
#define SCREENMODEMANAGER_HPP

#include <stdio.h>
#include "custom_graphics.hpp"

class ScreenModeManager
{
public:
	int start_mode;
	int end_mode;
	ScreenModeManager(int start_mode, int end_mode) : start_mode(start_mode), end_mode(end_mode)
	{
		set_mode(start_mode);
	}

	~ScreenModeManager()
	{
		set_mode(end_mode);
		printf("Entered mode: %d", end_mode);
	}
};

#endif