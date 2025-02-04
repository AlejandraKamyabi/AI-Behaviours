#include "TileMap.h"
#include <XEngine.h> // <> for external includes, "" for internal includes
#include <ImGui/Inc/imgui.h>

TileMap tileMap;
Path path;
int startX = 5;
int startY = 9;
int endX = 20;
int endY = 12;
//--------------------------------------------------

void GameInit()
{
	tileMap.LoadTiles("tiles.txt");
	tileMap.LoadMap("map.txt");
}

bool GameLoop(float deltaTime)
{
	

	ImGui::Begin("Pathfinding");
	ImGui::DragInt("StartX##", &startX, 1, 0, tileMap.GetColumns()- 1);
	ImGui::DragInt("StartY##", &startY, 1, 0, tileMap.GetRows() - 1);
	ImGui::DragInt("EndX##", &endX, 1, 0, tileMap.GetColumns() - 1);
	ImGui::DragInt("EndY##", &endY, 1, 0, tileMap.GetRows() - 1);
	if (ImGui::Button("RunBFS##")) {
		path = tileMap.FindPathBFS(startX, startY, endX, endY);

	}
	if (ImGui::Button("RunDFS##")) {
		path = tileMap.FindPathDFS(startX, startY, endX, endY);

	}
	if (ImGui::Button("RunDijkstra##")) {
		path = tileMap.FindPathDijkstra(startX, startY, endX, endY);

	}
	if (ImGui::Button("RunAStar##")) {
		path = tileMap.FindPathAStar(startX, startY, endX, endY);

	}
	if (X::IsMousePressed(0))
	{
		int x = X::GetMouseScreenX();
		int y = X::GetMouseScreenY();
		auto node = tileMap.GetClosestNode(x, y);
		if (node != nullptr)
		{
			startX = node->column;
			startY = node->row;
		}
	}
	if (X::IsMousePressed(1))
	{
		int x = X::GetMouseScreenX();
		int y = X::GetMouseScreenY();
		auto node = tileMap.GetClosestNode(x, y);
		if (node != nullptr)
		{
			endX = node->column;
			endY = node->row;
		}
	}
	ImGui::End();

	tileMap.Render();
	for (int i = 1; i < path.size(); ++i) {
		X::DrawScreenLine(path[i - 1], path[i], X::Colors::Red);
	}
	X::DrawScreenCircle(tileMap.GetPixelPosition(startX, startY), 10, X::Colors::Yellow);
	X::DrawScreenCircle(tileMap.GetPixelPosition(endX, endY), 10, X::Colors::Cyan);
	const bool quit = X::IsKeyPressed(X::Keys::ESCAPE);
	return quit;
}

void GameCleanup()
{

}

//--------------------------------------------------

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	X::Start("Pathfinding");
	GameInit();

	X::Run(GameLoop);

	GameCleanup();
	X::Stop();
	return 0;
}