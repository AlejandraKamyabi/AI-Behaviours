#pragma once

#include <AI.h>
#include <ImGui/Inc/imgui.h>
#include "Miner.h"
class GoHomeAndSleepUntilRestedState:public AI::State<Miner>
{
public:
	void Enter(Miner& agent) override
	{
		agent.SetLocation(Miner::LocationType::Home);
	}
	void Update(Miner& agent, float deltaTime) override
	{
		agent.ResetFatique();
		if (!agent.Wealthy())
		{
			agent.ChangeState(MinerStates::EnterMineAndDigForNugget);
		}
	}
	void Exit(Miner& agent) override
	{

	}
	void DebugUI() override
	{
		ImGui::Text("Miner is Resting");
	}
};
class EnterMineAndDigForNuggetState:public AI::State<Miner>
{
public:
	void Enter(Miner& agent) override
	{
		agent.SetLocation(Miner::LocationType::Mine);
	}
	void Update(Miner& agent, float deltaTime) override
	{
		agent.IncreaseFatique();
		agent.InreaseThirst();
		agent.AddGoldCarried(1);
		if (agent.PocketsFull())
		{
		
			agent.ChangeState(MinerStates::VisitBankAndDepositGold);
		}
		else if(agent.IsThirsty()) {

			agent.ChangeState(MinerStates::QuenchThirst);
		}


	}
	void Exit(Miner& agent) override
	{

	}
	void DebugUI() override
	{
		ImGui::Text("Miner is Digging For Gold");
	}

};
class QuenchThirstState:public AI::State<Miner>
{
public:
	void Enter(Miner& agent) override
	{
		agent.SetLocation(Miner::LocationType::Saloon);
	}
	void Update(Miner& agent, float deltaTime) override
	{
		agent.ResetThirst();
		if (!agent.IsThirsty())
		{
		
			agent.ChangeState(MinerStates::EnterMineAndDigForNugget);
		}
	}
	void Exit(Miner& agent) override
	{
		
	}
	void DebugUI() override
	{
		ImGui::Text("Miner is Drinking");
	}

};
class VisitBankAndDepositGoldState:public AI::State<Miner>
{
public:
	void Enter(Miner& agent) override
	{
		agent.SetLocation(Miner::LocationType::Bank);
	}
	void Update(Miner& agent, float deltaTime) override
	{
		agent.AddGoldToBank(1);
		if(agent.Wealthy()){
		
			agent.ChangeState(MinerStates::GoHomeAndSleepUntilRested);
		}
		else {
			agent.ChangeState(MinerStates::EnterMineAndDigForNugget);
		}
	}
	void Exit(Miner& agent) override
	{

	}
	void DebugUI() override {

		ImGui::Text("MIner is Depositing Gold into bank");
	}
};

