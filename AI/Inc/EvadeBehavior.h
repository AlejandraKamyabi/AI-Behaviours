#pragma once
#include "SteeringBehavior.h"

namespace AI
{
	class EvadeBehaviour : public SteeringBehavior
	{
	public:
		float DistanceFrom = 50.0f;
		X::Math::Vector2 Calculate(Agent& agent) override;
	
	};
}