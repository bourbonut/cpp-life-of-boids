#pragma once
#include <array>
#include <vector>
#include <utility>

#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myMath/utils.hpp"
#include "../controller/Color.h"


static int id = 0;

class Agent{
protected:
	Vec2 m_position;
	Vec2 m_velocity;
	Vec2 m_nextPosition;
	Vec2 m_nextVelocity;
	int m_bodySize;
	int m_viewAngle;
	int  m_range;
	float m_maxSpeed;
	Color m_color;
	std::array<float, 3> m_GLColor;
	bool m_toDestroy;

using pair = std::pair<Vec2, Agent *>;
using pairNP = std::pair<std::vector<pair>, std::vector<pair>>;

protected:
	Agent(const int& lVelocity, const int& uVelocity, const int& bodySize,
		const int& viewAngle);
	Agent(const Vec2& position, const Vec2& velocity, const int& bodySize,
		const int& viewAngle, const int& range);
	Agent(const Vec2& position, const Vec2& velocity, const int& bodySize,
		const int& viewAngle, const int& range, const float & maxSpeed, const Color& color);

public:
	virtual ~Agent() = default;
	int _id = ++id;
	virtual void computeLaws(const pairNP& neighbors) = 0;
	void prepareMove();
	void move();

	void setPosition(const Vec2& newPos);
	void setNextPosition(const Vec2& newPos);
	void setNextVelocity(const Vec2& newVel);
	void setVelocity(const Vec2& newVel);
	void setSize(int size);
	Vec2 getPosition() const;
	Vec2 getVelocity() const;
	Vec2 getNextVelocity() const;
	Vec2 getNextPosition() const;
	bool getDestruction();
	void setDestruction();
	int getRange() const;
	int getBodySize() const;
	int getViewAngle() const;
	void keepPositionInScreen(const float& width, const float& height);
	std::array<float, 3> getGLColor() const;

	std::string string() const;
	Agent& operator=(const Agent& other);

};
