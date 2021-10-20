#pragma once
#include "../model/Flock.hpp"


enum class Color { Red, Green, Blue, Default }; //TODO : make some colors

//Creates a complex flock with all options, including the actual flock, this function will be called by all the others 
Flock create_flock(int size, Color agent_colors, int agent_size, int agent_range, int agent_angle_view);

//Flock will be white
Flock generate_flock(int size, int agent_size, int agent_range, int agent_angle_view);

//Flocks will be given a size of 5
Flock generate_flock(int size, int agent_range, int agent_angle_view);

//Agents will be given a random position and a random color, size of 5 and birds are doves
Flock generate_random_flock();

Flock generate_fully_random_flock();

Flock generate_pigeons_flock(int size);

//angle view is 270, range is 50
Flock generate_dove_flock(int size);

Color random_color();