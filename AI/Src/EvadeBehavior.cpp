#include "Precomplied.h"
#include "EvadeBehavior.h"
#include "Agent.h"

using namespace AI;

X::Math::Vector2 AI::EvadeBehaviour::Calculate(Agent& agent)
{
	X::Math::Vector2 Escape = X::Math::Vector2::Zero();
	X::Math::Vector2 desiredVelocity = X::Math::Vector2::Zero();

	const auto agentToDest = agent.target->destination - agent.position;
	const float distToDest = X::Math::Magnitude(agentToDest);

	if (distToDest < DistanceFrom)
	{
		desiredVelocity = -(agentToDest / distToDest) * agent.maxSpeed;
	}

	Escape = desiredVelocity - agent.velocity;

	if (GetDebug())
	{
		X::DrawScreenLine(agent.position, agent.position + desiredVelocity, X::Colors::Purple);
		X::DrawScreenLine(agent.position, agent.position + agent.velocity, X::Colors::HotPink);
		X::DrawScreenCircle(agent.target->destination, 20.0f, X::Colors::Aqua);
	}

	return Escape;
}