#pragma once
#include "Graph.h"

class MatrixGraph : public Graph
{

    std::vector<std::vector<int>> Adjacency;
    void initializeAdjacency(); //funkcja ma na celu wyczyscic vector oraz zarezerwowac miejsce na podany NumberOfVectors
    void randomConection(std::vector<std::pair<int, int>>& possibleEdges, int NumberOfEdges);
    // void PrintGraph();
public:

    MatrixGraph(int Vertices, int start);
    MatrixGraph() = default;
};