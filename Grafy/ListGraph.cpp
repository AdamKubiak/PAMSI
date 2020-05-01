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
    if (!Adjacency.empty())
        Adjacency.clear();

    Adjacency.resize(NumberOfVertices);
}

void ListGraph::randomConection(std::vector<std::pair<int, int>>& possibleEdges, int NumberOfEdges)
{
    for (int i = 0; i < NumberOfEdges; ++i)
    {
        
        int edgeIndex = std::rand() % possibleEdges.size();
        int weight = std::rand() % 10 +1;//dodaje jeden aby waga nie wynosi³a 0
       


        std::pair<int, int> temp = possibleEdges[edgeIndex];
        auto toRemove = possibleEdges.begin() + edgeIndex;
        possibleEdges.erase(toRemove);
        Adjacency[temp.first].push_back(std::make_pair(temp.second, weight));
        Adjacency[temp.second].push_back(std::make_pair(temp.first, weight));
        
    }

    //std::cout << Adjacency.size();

    for (int i=0;i<Adjacency.size();i++){
        std::cout << i << " ->";
      for (int j = 0; j < Adjacency[i].size(); j++) {
          std::cout<< Adjacency[i][j].first << " "<<"("<< Adjacency[i][j].second << ") ";
      }
      std::cout << std::endl;
    }
}
