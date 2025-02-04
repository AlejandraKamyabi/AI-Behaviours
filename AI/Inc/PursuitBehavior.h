#pragma once
#include "SteeringBehavior.h"

namespace AI
{
	class PursuitBehaviour : public SteeringBehavior
	{
	public:
		X::Math::Vector2 Calculate(Agent& agent) override;
	};
}