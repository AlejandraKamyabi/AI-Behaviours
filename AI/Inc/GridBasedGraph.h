#pragma once
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
namespace AI
{
	class  GridBasedGraph
	{
	public:
		enum Direction {

			North,
			South,
			East,
			West,
			NorthEast,
			SouthEast,
			NorthWest,
			SouthWest
		};
		struct Node
		{
			std::array<Node*, 8> neighbors = {};
			int column = 0;
			int row = 0;

			Node* parent = nullptr;
			bool opened = false;
			bool closed = false;
			float cost = 0.0f;
			float heuristic = 0.0f;

			void Reset() {
				parent = nullptr;
				opened = false;
				closed = false;
				cost = 0.0f;
				heuristic = 0.0f;
			}

		};
		void Initialize(int columns, int rows);
		void ResetSearchParams();
		Node* GetNode(int x, int y);
		const Node* GetNode(int x, int y) const;

		int GetColumns() const { return mColumns; }
		int GetRows() const { return mRows; }
	private:
		int GetIndex(int x, int y) const;

		std::vector<Node> mNodes;
		int mColumns = 0;
		int mRows = 0;
	};
	
}

//[][][][][][][][][][]	
//[][][][][][][][][][]		
//[][][][][][][][][][]
//[][][][][][][][][][]
//[][][][][][][][][][]