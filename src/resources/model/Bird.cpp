#include <array>
#include <vector>
#include <utility>

#include "Bird.hpp"
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myMath/utils.hpp"

using pair = std::pair<Vec2, Agent *>;
using pairNP = std::pair<std::vector<pair>, std::vector<pair>>;

Bird::Bird() : Agent(-5, 5, 6, 270){};

Bird::Bird(const Vec2& position, const Vec2& velocity) : Agent(position, velocity, 6, 270, 50){};

Bird::Bird(const Vec2& position, const Vec2& velocity, const int& bodySize, const int& viewAngle, const int& range, const float& maxSpeed, const Color& color):
  Agent(position, velocity, bodySize, viewAngle, range, maxSpeed, color), m_cohesionLaw(), m_alignmentLaw(), m_separationLaw(){};

Bird::Bird(const Vec2& position, const Vec2& velocity, const int& bodySize, const int& viewAngle,
           const int& range, const float& maxSpeed, const Color& color,
           const CohesionLaw& cohesionLaw, const AlignmentLaw& alignmentLaw,
           const SeparationLaw& separationLaw):
  Bird(position, velocity, bodySize, viewAngle, range, maxSpeed, color) {
    m_cohesionLaw = cohesionLaw;
    m_alignmentLaw = alignmentLaw;
    m_separationLaw = separationLaw;
};

void Bird::computeLaws(const pairNP& neighbors) {
  const std::vector<pair> neighborsBird = std::get<0>(neighbors);
  const std::vector<pair> neighborsPredator = std::get<1>(neighbors);
  Vec2 vecCohesion = m_cohesionLaw.compute(*this, neighborsBird);
  Vec2 vecAlignment = m_alignmentLaw.compute(*this, neighborsBird);
  Vec2 vecSeparation = m_separationLaw.compute(*this, neighborsBird);
  Vec2 vecFleeing = m_separationLaw.compute(*this, neighborsPredator);
  Vec2 vec_displacement = vecAlignment + vecCohesion + vecSeparation + vecFleeing * 50.f;
  float norm = vec_displacement.norm();

  if (norm > 5) vec_displacement = vec_displacement / norm;

  m_nextVelocity = (m_velocity + vec_displacement);
  if (m_nextVelocity.norm() > m_maxSpeed) m_nextVelocity = m_nextVelocity.normalize() * m_maxSpeed;
};

std::ostream& operator<<(std::ostream& os, const Bird& obj)
{
    return os << "Bird(" << obj.string() << ")";
}
