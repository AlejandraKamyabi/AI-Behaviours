#include "Precomplied.h"
#include "DFS.h"
using namespace AI;

bool DFS::Run(GridBasedGraph& graph, int startX, int startY, int endX, int endY)
{
	graph.ResetSearchParams();
	mOpenList.clear();
	mClosedList.clear();
	auto node = graph.GetNode(startX, startY);
	mOpenList.push_back(node);
	node->opened = true;

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

				if (neighbor == nullptr || neighbor->opened)
				{
					continue;
				}
				mOpenList.push_back(neighbor);
				neighbor->opened = true;
				neighbor->parent = node;
			}
		
		}
		mClosedList.push_back(node);
		node->closed;

	}
	return found;
}