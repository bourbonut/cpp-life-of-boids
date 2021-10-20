#include "flock_generator.hpp"
#include "../model/Flock.hpp"
#include <vector>

Flock create_bird_flock(int size, Color agent_color, int agent_size, int agent_range, int agent_angle_view, Vec2 agent_position, Vec2 agent_velocity)
{
	std::vector<Agent*> agents;

	int reserve_size = size * 2;
	agents.reserve(reserve_size);

	for (int i = 0; i < size; ++i) {
		agents.push_back(new Bird{agent_position, agent_velocity, agent_size, agent_angle_view, agent_range, agent_color});
	}

	return agents;
};

Flock create_bird_flock(int size, Color agent_color, int agent_size, int agent_range, int agent_angle_view) {
	std::vector<Agent*> agents;

	int reserve_size = size * 2;
	agents.reserve(reserve_size);

	for (int i = 0; i < size; ++i) {
		agents.push_back(new Bird{ randomVec2Generation(-500, 500), randomVec2Generation(-10, 10), agent_size, agent_angle_view, agent_range, agent_color });
	}

	return agents;
}


Flock generate_pigeons_flock(int size)
{
	return create_bird_flock(size, Color::White, 6, 50, 320);
}

Flock generate_dove_flock(int size) {
	return create_bird_flock(size, Color::White, 6, 50, 270);
}

Flock generate_duck_flock(int size)
{
	return create_bird_flock(size, Color::White, 6, 70, 360);
}
