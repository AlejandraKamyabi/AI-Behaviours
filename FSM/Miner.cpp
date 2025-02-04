#include "MinerStates.h"

void Miner::Initialize() {
	mLocation = LocationType::Home;
	mGoldCarried = 0;
	mMoneyInBank = 0;
	mThirst = 0;
	mFatigue = 0;
	mStateMachine = new AI::StateMachine<Miner>(*this);
	mStateMachine->AddState<GoHomeAndSleepUntilRestedState>();
	mStateMachine->AddState<EnterMineAndDigForNuggetState>();
	mStateMachine->AddState<QuenchThirstState>();
	mStateMachine->AddState<VisitBankAndDepositGoldState>();
	mStateMachine->ChangeState(0);

}
void Miner::Terminate() {

	delete mStateMachine;
	mStateMachine = nullptr;

}
void Miner::Update(float deltaTime)
{
	mStateMachine->Update(deltaTime);

}
void Miner::ChangeState(MinerStates newState)
{
	mStateMachine->ChangeState((int)newState);

}
void Miner::DebugUI() 
{
	mStateMachine->DebugUI();
	ImGui::Text("Miner States: Bank [%d] Gold [%d] Thirst [%d] Fatique [%d]", mMoneyInBank, mGoldCarried, mThirst, mFatigue);
}

Miner::LocationType Miner::GetLocationType(){

	return mLocation;
}
bool Miner::IsThirsty() const 
{
	return mThirst >= 5;
}
bool Miner::IsTired() const
{
	return mFatigue >= 10;
}
bool Miner::PocketsFull() const 
{
	return mGoldCarried >= 10;
}
bool Miner::Wealthy() const 
{
	return mMoneyInBank > 100;
}
bool Miner::Rested() const 
{
	return true;

}

void Miner::SetLocation(LocationType location) 
{
	mLocation = location;
}
void Miner::IncreaseFatique() 
{
	mFatigue++;
}
void Miner::InreaseThirst(){
	mThirst++;

}
void Miner::AddGoldCarried(int amount) 
{
	mGoldCarried += amount;
}
void Miner::AddGoldToBank(int amount) 
{
	mMoneyInBank += mGoldCarried;
}


void Miner::ResetFatique() 
{
	mFatigue = 0;
}

void Miner::ResetThirst()
{
	mThirst = 0;
}
void Miner::ResetRest() 
{
	
}