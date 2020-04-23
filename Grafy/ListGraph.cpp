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

void ListGraph::randomEdges(std::vector<std::pair<int, int>>& possibleEdges, int NumberOfEdges)
{
    for (int i = 0; i < NumberOfEdges; ++i)
    {
        int cost = std::rand() % 50 + 1;
        int edgeIndex = std::rand() % possibleEdges.size();
        std::cout<<possibleEdges.size()<<std::endl;
        std::cout<<edgeIndex<<std::endl;


        std::pair<int, int> temp = possibleEdges[edgeIndex];
        auto toRemove = possibleEdges.begin() + edgeIndex;
        possibleEdges.erase(toRemove);
        AdjacencyList[temp.first].emplace_back(std::make_pair(temp.second, cost));
        //AdjacencyList[e.second].emplace_back(std::make_pair(e.first, cost));
        
    }

    //std::cout << Adjacency.size();

    for (int i=0;i<AdjacencyList.size();i++){
       
      for (int j = 0; j < AdjacencyList[i].size(); j++) {
        std::cout <<i<< " ->" << AdjacencyList[i][j].first << " "
                  <<"("<< AdjacencyList[i][j].second << ")" << std::endl;
      }
    }
}
