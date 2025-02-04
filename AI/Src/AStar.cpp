#include "Precomplied.h"
#include "AStar.h"
using namespace AI;

bool AStar::Run(GridBasedGraph& graph, int startX, int startY, int endX, int endY, GetCost getCost, GetHeuristic getHeuristic)
{
	graph.ResetSearchParams();
	mOpenList.clear();
	mClosedList.clear();
	auto node = graph.GetNode(startX, startY);
	mOpenList.push_back(node);
	node->opened = true;
	auto endNode = graph.GetNode(endX, endY);
	bool found = false;
	while (!found && !mOpenList.empty())
	{

		node = mOpenList.back();
		mOpenList.pop_back();

		if (node->column == endX && node->row == endY) {
			found = true;

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
					neighbor->heuristic = getHeuristic(neighbor,endNode);
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
			if (a->cost < b->cost) {
				return a->heuristic < b->heuristic;
			}
			return a->cost < b->cost;
		};
		mOpenList.sort(sortCost);
		mClosedList.push_back(node);
		node->closed;

	}
	return found;
}