#include "Graph.h"
#include <iostream>
#include <ctime>



void Graph::GenerateRandomGraph(int size, double density)
{
    NumberOfVertices = size;

    //srand(time(NULL));
    StartingVertex = std::rand() % NumberOfVertices;
    initializeAdjacency();

    int NumberOfEdges = (int)(density * NumberOfVertices * (NumberOfVertices - 1));

    std::vector<std::pair<int,int>> possibleEdges;
    for (int i = 0; i < NumberOfVertices; ++i)
    {
        for (int j = 1; j < NumberOfVertices; ++j)
        {
            possibleEdges.push_back(std::make_pair(i, j));
        }
    }
randomConection(possibleEdges, NumberOfEdges);
}