#include "Precomplied.h"
#include "SteeringModule.h"

using namespace AI;

SteeringModule::SteeringModule(Agent& agent)
	: mAgent(agent)
{
}

X::Math::Vector2 SteeringModule::Calculate()
{
	X::Math::Vector2 totalForce;

	for (auto& behavior : mBehavior)
	{
		if (behavior->IsActive())
		{
			totalForce += behavior->Calculate(mAgent) * behavior->GetWeight();
		}
	}
	return totalForce;
}