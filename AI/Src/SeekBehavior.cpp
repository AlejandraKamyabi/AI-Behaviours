#include "Precomplied.h"
#include "SeekBehavior.h"
#include "Agent.h"

using namespace AI;

X::Math::Vector2 AI::SeekBehavior::Calculate(Agent& agent)
{
	const auto agentToDest = agent.destination - agent.position;
	const float distToDest = X::Math::Magnitude(agentToDest);
	if (distToDest <= 0.1f)
	{
		return X::Math::Vector2::Zero();
	}

	const auto desiredVelocity = (agentToDest / distToDest) * agent.maxSpeed;
	const auto seekForce = desiredVelocity - agent.velocity;

	if (GetDebug())
	{
		X::DrawScreenLine(agent.position, agent.position + desiredVelocity, X::Colors::Purple);
		X::DrawScreenLine(agent.position, agent.position + agent.velocity, X::Colors::HotPink);
		X::DrawScreenCircle(agent.target->destination, 20.0f, X::Colors::Aqua);
	}

	return seekForce;
}
