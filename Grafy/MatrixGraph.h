#pragma once
#include "Graph.h"

class MatrixGraph : public Graph
{

    std::vector<std::vector<int>> Adjacency;
    
    // void PrintGraph();
public:
    void initializeAdjacency(); //funkcja ma na celu wyczyscic vector oraz zarezerwowac miejsce na podany NumberOfVectors
    void randomConection(std::vector<std::pair<int, int>>& possibleEdges, int NumberOfEdges);
    void addVertex(int vertex, int neighbour, int pathCost);
    MatrixGraph(int Vertices, int start);
    MatrixGraph() {};
    void dijkstra();
};