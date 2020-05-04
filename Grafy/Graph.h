#pragma once
#include <vector>
#include <string>
class Graph
{
protected:
	int NumberOfVertices;
	int StartingVertex;
	int forFileNumberOfEdges;
	std::vector<int> Previous;
	std::vector<int> Distances;

	virtual void LoadFromFile(std::string filename) = 0;
	virtual void initializeAdjacency() = 0;
	virtual void randomConection(std::vector<std::pair<int, int>>& possibleEdges, int NumberOfEdges) = 0;
	void virtual addVertex(int vertex, int neighbour, int pathCost)=0;
	virtual void PrintDijkstra() = 0;

public:
	virtual void dijkstra() = 0;
	void GenerateRandomGraph(int size, double density);
	Graph() :StartingVertex(0), NumberOfVertices(0) {};
};