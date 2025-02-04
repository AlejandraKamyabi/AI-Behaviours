#include "Precomplied.h"
#include "Dijkstra.h"
#include "Precomplied.h"
#include "DFS.h"
using namespace AI;

bool Dijkstra::Run(GridBasedGraph& graph, int startX, int startY, int endX, int endY, GetCost getCost)
{
	graph.ResetSearchParams();
	mOpenList.clear();
	mClosedList.clear();
	auto node = graph.GetNode(startX, startY);
	mOpenList.push_back(node);
	node->opened = true;
	GridBasedGraph::Node* endNode = nullptr;

	while (!mOpenList.empty())
	{

		node = mOpenList.back();
		mOpenList.pop_back();

		if (node->column == endX && node->row == endY) {
			
			endNode = node;
		}
		else
		{

			for (auto neighbor : node->neighbors)
			{

				if (neighbor == nullptr || neighbor->closed)
				{
					continue;
				}
				float cost = node->cost + getCost(node, neighbor);
				if (!neighbor->opened) {
					mOpenList.push_back(neighbor);
					neighbor->opened = true;
					neighbor->parent = node;
					neighbor->cost = cost;
				}
				else if (cost < neighbor->cost)
				{
					neighbor->parent = node;
					neighbor->cost = cost;
				}
			}
			
		}
		auto sortCost = [](const GridBasedGraph::Node* a, const GridBasedGraph::Node* b)
		{
			return a->cost < b->cost;
		};
		mOpenList.sort(sortCost);
		mClosedList.push_back(node);
		node->closed = true;

	}
	mClosedList.push_back(node);
	return endNode != nullptr;
}