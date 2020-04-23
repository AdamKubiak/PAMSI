#include "Graph.h"

#include <climits>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

Graph::Graph(int Vertices, int start) : NumberOfVertices(Vertices), StartingVertex(start)
{}

void Graph::GenerateRandomGraph(int size, double density)
{
    NumberOfVertices = size;

    srand(time(NULL));
    StartingVertex = std::rand() % NumberOfVertices;

    int edgesNumber = (int)(density * NumberOfVertices * (NumberOfVertices - 1)) / 2;

    std::vector<std::pair<int,int>> possibleEdges;
    for (int i = 0; i < NumberOfVertices; ++i)
    {
        for (int j = i + 1; j < NumberOfVertices; ++j)
        {
            possibleEdges.emplace_back(std::make_pair(i, j));
        }
    }

    initializeAdjacency();
    randomEdges(possibleEdges, edgesNumber);

}