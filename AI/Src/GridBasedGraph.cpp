#include "Precomplied.h"
#include "GridBasedGraph.h"

using namespace AI;

void GridBasedGraph::Initialize(int columns, int rows) {
	mNodes.clear();
	mNodes.reserve(columns * rows);
	mColumns = columns;
	mRows = columns;

	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < columns; ++c) {
			
			auto& node = mNodes.emplace_back();
			node.column = c;
			node.row = r;
		}
	}
}
void GridBasedGraph::ResetSearchParams() {
	for (auto& node : mNodes) {
		node.Reset();
	}
}
GridBasedGraph::Node* GridBasedGraph::GetNode(int x, int y) {
	if (x >= 0 && x < mColumns && y >= 0 && y < mRows) {
		const int index = GetIndex(x, y);
		if (index < mNodes.size())
		{
			return &mNodes[index];

		}
	}
	return nullptr;
}
const GridBasedGraph::Node* GridBasedGraph::GetNode(int x, int y) const {
	if (x >= 0 && x < mColumns && y >= 0 && y < mRows) {
		const int index = GetIndex(x, y);
		if (index < mNodes.size())
		{
			return &mNodes[index];

		}
	}
	return nullptr;
}

int GridBasedGraph::GetIndex(int x, int y) const {
	return x + (y * mColumns);
}
