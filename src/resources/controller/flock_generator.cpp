#include "flock_generator.hpp"
#include "../model/Flock.hpp"
#include "../../lib/myLaws/AlignmentLaw.hpp"
#include "../../lib/myLaws/CohesionLaw.hpp"
#include "../../lib/myLaws/SeparationLaw.hpp"
#include <vector>

Flock create_bird_flock(int size, Color agent_color, int agent_size, int agent_range, int agent_angle_view, Vec2 agent_position, Vec2 agent_velocity, float sep_relax, float cohe_relax, float align_relax, float maxSpeed)
{
	CohesionLaw coLaw(cohe_relax);
	SeparationLaw sepLaw(sep_relax);
	AlignmentLaw aligLaw(align_relax);

	std::vector<Agent*> agents;

	int reserve_size = size * 2;
	agents.reserve(reserve_size);

	for (int i = 0; i < size; ++i) {
		agents.push_back(new Bird{agent_position, agent_velocity, agent_size, agent_angle_view, agent_range, maxSpeed, agent_color, coLaw, aligLaw, sepLaw });
	}

	return Flock{ agents };
};

Flock create_bird_flock(int size, Color agent_color, int agent_size, int agent_range, int agent_angle_view, float sep_relax, float cohe_relax, float align_relax, float maxSpeed) {
	std::vector<Agent*> agents;

	CohesionLaw coLaw(cohe_relax);
	SeparationLaw sepLaw(sep_relax);
	AlignmentLaw aligLaw(align_relax);

	int reserve_size = size * 2;
	agents.reserve(reserve_size);

	for (int i = 0; i < size; ++i) {
		agents.push_back(new Bird{ randomVec2Generation(-500, 500), randomVec2Generation(-10, 10), agent_size, agent_angle_view, agent_range, maxSpeed, agent_color, coLaw, aligLaw, sepLaw });
	}

	return Flock{ agents };
}

Flock generate_fully_random_bird_flock()
{
	int flock_size = random_float(20, 500);
	int range; 
	int angle_view; 
	int agent_size;
	float cohesion_relax;
	float sep_relax;
	float align_relax;
	float speed_relax;
	Vec2 position;
	Vec2 velocity;
	Color agent_color = Color::Default;

	std::vector<Agent*> agents;

	int reserve_size = flock_size * 2;
	agents.reserve(reserve_size);

	for (int i = 0; i < flock_size; ++i) {
		range = random_float(5, 100);
		angle_view = random_float(100, 360);
		agent_size = random_float(2, 20);
		position = randomVec2Generation(0, 500);
		velocity = randomVec2Generation(-10, 10);
		speed_relax = random_float(1, 30);
		align_relax = random_float(-0.5, 2);
		sep_relax = random_float(-0.5, 2);
		cohesion_relax = random_float(0, 1);
		//agent_color = random_color();

		agents.push_back(new Bird{ position, velocity, agent_size, angle_view, range, speed_relax, agent_color, CohesionLaw(cohesion_relax), AlignmentLaw(align_relax), SeparationLaw(sep_relax) });
	}

	return Flock{ agents };
}

Flock generate_random_bird_flock(Vec2 inf_sup_size, Vec2 inf_sup_range, Vec2 inf_sup_agent_size, Vec2 inf_sup_agent_angle_view, Vec2 inf_sup_agent_position, Vec2 inf_sup_agent_velocity, Vec2 inf_sup_speed_relax)
{
	int flock_size = random_float(inf_sup_size.x, inf_sup_size.y);
	int range = random_float(inf_sup_range.x, inf_sup_range.y);
	int angle_view = random_float(inf_sup_agent_angle_view.x, inf_sup_agent_angle_view.y);
	int agent_size = random_float(inf_sup_agent_size.x, inf_sup_agent_size.y);
	float cohesion_relax = 1/random_float(-10,10);
	float sep_relax = 1/random_float(-10,10);
	float align_relax = 1/random_float(-10,10);
	float speed_relax = random_float(inf_sup_speed_relax.x, inf_sup_speed_relax.y);


	//Change to random color 
	return create_bird_flock(flock_size, Color::Default, agent_size, range, angle_view, sep_relax, cohesion_relax, align_relax, speed_relax);
}

//TODO : Change 
Flock generate_parrot_flock(int size)
{
	float cohesion_relax = 0.0002f;
	float sep_relax = 0.9f ;
	float align_relax = 0.3;
	return create_bird_flock(size, Color::Green, 6, 50, 320, sep_relax, cohesion_relax, align_relax, 1.f);
}

Flock generate_dove_flock(int size) {
	float cohesion_relax = 0.0004;
	float sep_relax = 1.f;
	float align_relax = 0.05;
	return create_bird_flock(size, Color::White, 6, 50, 270, sep_relax, cohesion_relax, align_relax, 10.f);
}

Flock generate_duck_flock(int size)
{
	float cohesion_relax = 0.00008f;
	float sep_relax = 0.5f;
	float align_relax = 0.9f;
	return create_bird_flock(size, Color::White, 6, 70, 360, sep_relax, cohesion_relax, align_relax, 5.f);
}

//TODO : Change color to black or grey
Flock generate_ant_flock(int size) {
	float cohesion_relax = 0.0000008f;
	float sep_relax = 2.5f;
	float align_relax = -1.f;
	return create_bird_flock(size, Color::White, 4, 20, 360, sep_relax, cohesion_relax, align_relax, 15.f);
}

Flock generate_fly_flock(int size) {
	float cohesion_relax = 0.08f;
	float sep_relax = 1.f;
	float align_relax = 0.2f;
	return create_bird_flock(size, Color::White, 4, 40, 360, sep_relax, cohesion_relax, align_relax, 9.f);
}