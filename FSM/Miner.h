#pragma once
#include <AI.h>
enum MinerStates {

	GoHomeAndSleepUntilRested,
	EnterMineAndDigForNugget,
	QuenchThirst,
	VisitBankAndDepositGold

};
class Miner {
     public:
		enum LocationType 
		{
			Home,
			Mine,
			Saloon,
			Bank

		};
		Miner() = default;
		void Initialize();
		void Terminate();
		void Update(float deltaTime);
		void ChangeState(MinerStates pNewState);
		void DebugUI();

		LocationType GetLocationType();
		bool IsThirsty() const;
		bool IsTired() const;
		bool PocketsFull() const;
		bool Wealthy() const;
		bool Rested() const;

		void SetLocation(LocationType location);
		void IncreaseFatique();
	    void InreaseThirst();
		void AddGoldCarried(int amount);
		void AddGoldToBank(int amount);
		void ResetFatique();
		void ResetThirst();
		void ResetRest();

     private:
	    AI::StateMachine<Miner>* mStateMachine;
		LocationType mLocation;
		int mGoldCarried; 
		int mMoneyInBank; 
		int mThirst; 
		int mFatigue; 


};