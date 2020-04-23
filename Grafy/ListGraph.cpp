#include "ListGraph.h"
#include <iostream>

ListGraph::ListGraph(int Vertices, int start)
    : Graph(Vertices, start)
{
    AdjacencyList.resize(Vertices);

}

void ListGraph::initializeAdjacencyList()
{
    if (!AdjacencyList.empty())
        AdjacencyList.clear();

    AdjacencyList.resize(NumberOfVertices);
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
        AdjacencyList[temp.first].emplace_back(std::make_pair(temp.second, weight));
        AdjacencyList[temp.second].emplace_back(std::make_pair(temp.first, weight));
        
    }

    //std::cout << Adjacency.size();

    for (int i=0;i<AdjacencyList.size();i++){
        std::cout << i << " ->";
      for (int j = 0; j < AdjacencyList[i].size(); j++) {
          std::cout<< AdjacencyList[i][j].first << " "<<"("<< AdjacencyList[i][j].second << ") ";
      }
      std::cout << std::endl;
    }
}
