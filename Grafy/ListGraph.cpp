#include "ListGraph.h"

#include <queue>
#include <algorithm>
#include <climits>
#include <iostream>

ListGraph::ListGraph(int Vertices, int start)
    : Graph(Vertices, start)
{
    Adjacency.resize(Vertices);

}

void ListGraph::initializeAdjacency()
{
    if (!Adjacency.empty()) Adjacency.clear();

    Adjacency.resize(NumberOfVertices);
}

void ListGraph::randomEdges(std::vector<std::pair<int, int>>& possibleEdges, int NumberOfEdges)
{
    for (int i = 0; i < NumberOfEdges; ++i)
    {
        int cost = std::rand() % 50 + 1;
        int edgeIndex = std::rand() % possibleEdges.size();
        std::cout<<possibleEdges.size()<<std::endl;
        std::cout<<edgeIndex<<std::endl;


        std::pair<int, int> e = possibleEdges.at(edgeIndex);
        auto toRemove = possibleEdges.begin() + edgeIndex;
        possibleEdges.erase(toRemove);
        Adjacency[e.first].emplace_back(std::make_pair(e.second, cost));
        Adjacency[e.second].emplace_back(std::make_pair(e.first, cost));
    }


}

