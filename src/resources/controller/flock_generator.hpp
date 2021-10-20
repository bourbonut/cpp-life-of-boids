#pragma once
#include "../model/Flock.hpp"
#include "Color.h"


//Creates a complex bird flock with all options, including the actual flock
//ALL flocks are in same position
Flock create_bird_flock(int size, Color agent_color, int agent_size, int agent_range, int agent_angle_view, Vec2 agent_position, Vec2 agent_velocity);

//Same with random positions
Flock create_bird_flock(int size, Color agent_color, int agent_size, int agent_range, int agent_angle_view);

//Agents will be given a random position and a random color, size of 5 and birds are doves
Flock generate_random_flock();

//everything randomized
Flock generate_fully_random_flock();

//angle view is about 320, range 50
Flock generate_pigeons_flock(int size);

//angle view is 270, range is 50
Flock generate_dove_flock(int size);

//view 360 and range 70
Flock generate_duck_flock(int size);

Color random_color();