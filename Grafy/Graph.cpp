#include "Graph.h"

#include <iostream>
#include <fstream>
#include <ctime>



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
            possibleEdges.push_back(std::make_pair(i, j));
        }
    }

    if (!Previous.empty()) 
        Previous.clear();

   Previous.reserve(NumberOfVertices);

    if (!Distances.empty())
        Distances.clear();

    Distances.resize(NumberOfVertices, 999);

    initializeAdjacency();
    randomConection(possibleEdges, edgesNumber);
}