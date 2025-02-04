#pragma once
#include "SteeringBehavior.h"

namespace AI
{
	class ArriveBehaviour : public SteeringBehavior
	{
	public:
		enum class Deacceleration
		{
			Fast,
			Normal,
			Slow
		};

		X::Math::Vector2 Calculate(Agent& agent) override;
	};
}