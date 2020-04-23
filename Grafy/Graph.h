#pragma once

#include <vector>
#include <map>
#include <string>
class Graph
{
protected:
	int NumberOfVertices;
	int StartingVertex;

	virtual void initializeAdjacencyList() = 0;
	virtual void randomEdges(std::vector<std::pair<int, int>>& possibleEdges, int NumberOfEdges) = 0;
	//virtual void PrintGraph();

public:

	Graph(int Vertices, int start);
	Graph() = default;
	
	//virtual void dijkstra() = 0;
	void GenerateRandomGraph(int size, double density);

	virtual ~Graph() {}
};