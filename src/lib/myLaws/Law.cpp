#include "Law.hpp"
#include "../myMath/Vec2.hpp"
#include "../myMath/utils.hpp"
#include "../../resources/model/Agent.hpp"
#include <vector>

Law::Law(const float& relaxation) : m_relaxation{ relaxation } {};
