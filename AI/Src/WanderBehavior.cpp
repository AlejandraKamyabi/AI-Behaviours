#include "Precomplied.h"
#include "WanderBehavior.h"
#include "Agent.h"

using namespace AI;

X::Math::Vector2 AI::WanderBehavior::Calculate(Agent& agent)
{
	auto newWanderTarget = mLocalWanderTarget + (X::RandomUnitCircle() * mWanderJitter);  

	newWanderTarget = X::Math::Normalize(newWanderTarget) * mWanderRadius;
	mLocalWanderTarget = newWanderTarget;

	newWanderTarget += X::Math::Vector2(0.0f, mWanderDistance);

	const auto worldTransform = agent.GetWorldTransform();
	agent.destination = X::Math::TransformCoord(newWanderTarget, worldTransform);

	const auto agentDist = agent.destination - agent.position;
	const float distToDest = X::Math::Magnitude(agentDist);
	if (distToDest <= 0.01f)
	{
		return X::Math::Vector2::Zero();
	}

	const auto desiredVelocity = (agentDist / distToDest) * agent.maxSpeed;
	auto seekForce = desiredVelocity - agent.velocity;

	if (GetDebug())
	{
		const auto wanderCenter = X::Math::TransformCoord({ 0.0f, mWanderDistance }, worldTransform);
		X::DrawScreenCircle(wanderCenter, mWanderRadius, X::Colors::LightBlue);
		X::DrawScreenDiamond(agent.destination, 3.0f, X::Colors::DeepPink);
		X::DrawScreenLine(agent.position, agent.destination, X::Colors::Red);
	}

	return seekForce;
}

void AI::WanderBehavior::Setup(float radius, float distance, float jitter)
{
	mWanderRadius = radius;
	mWanderDistance = distance;
	mWanderJitter = jitter;
}