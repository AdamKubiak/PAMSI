#pragma once

#include <vector>
#include <map>
#include <string>
class Graph
{
protected:
	int NumberOfVertices;
	int StartingVertex;
	std::vector<int> Previous;
	std::vector<int> Distances;

	virtual void initializeAdjacency() = 0;
	virtual void randomConection(std::vector<std::pair<int, int>>& possibleEdges, int NumberOfEdges) = 0;
	//virtual void PrintGraph();

public:

	
	
	virtual void dijkstra() = 0;
	 void GenerateRandomGraph(int size, double density);
};