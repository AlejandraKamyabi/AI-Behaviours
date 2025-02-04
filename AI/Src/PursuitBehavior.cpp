#include "Precomplied.h"
#include "PursuitBehavior.h"
#include "Agent.h"

using namespace AI;

X::Math::Vector2 AI::PursuitBehaviour::Calculate(Agent& agent)
{
	const auto agentDest = agent.target->destination - agent.position;
	const float distToDest = X::Math::Magnitude(agentDest);
	if (distToDest <= 0.1f)
	{
		return X::Math::Vector2::Zero();
	}

	const auto Velocity = (agentDest / distToDest) * agent.maxSpeed;
	const auto Force = Velocity - agent.velocity;

	if (GetDebug())
	{
		X::DrawScreenLine(agent.position, agent.position + Velocity, X::Colors::Purple);
		X::DrawScreenLine(agent.position, agent.position + agent.velocity, X::Colors::HotPink);
		X::DrawScreenCircle(agent.target->destination, 20.0f, X::Colors::Aqua);
	}

	return Force;
}