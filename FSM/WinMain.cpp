#include <XEngine.h>
#include <ImGui/Inc/imgui.h>
#include "Miner.h"
Miner miner;
float timer = 0.0f;
float TimeToCount = 3.0;
void GameInit()
{
	miner.Initialize();
}

bool GameLoop(float deltaTime)
{
	if (X::IsKeyPressed(X::Keys::SPACE)) {
		miner.Update(deltaTime);
	}

	timer -= deltaTime;
	while (timer <= 0.0f) 
	{
		timer += TimeToCount;
	}
	ImGui::Begin("FSM");
	miner.DebugUI();
	ImGui::End();
	const bool quit = X::IsKeyPressed(X::Keys::ESCAPE);
	return quit;
}

void GameCleanup()
{
	miner.Terminate();
}

void RenderDebugUI()
{
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	X::Start("Pathfinding");
	GameInit();

	X::Run(GameLoop);

	GameCleanup();
	X::Stop();
	return 0;
}