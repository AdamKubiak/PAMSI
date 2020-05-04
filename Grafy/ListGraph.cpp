#include "ListGraph.h"
#include <queue>
#include <iostream>
#include <ctime>
#include <fstream>

ListGraph::ListGraph(int Vertices, int start)
{
    NumberOfVertices = Vertices;
    Adjacency.resize(Vertices);
    StartingVertex = start;
}

void ListGraph::addVertex(int vertex, int neighbour, int weight)
{
    Adjacency[vertex].push_back(std::make_pair(neighbour, weight));
}

void ListGraph::initializeAdjacency()
{
    if (!Adjacency.empty())
        Adjacency.clear();

    Adjacency.resize(NumberOfVertices);

    if (!Previous.empty())
        Previous.clear();

    Previous.reserve(NumberOfVertices);

    if (!Distances.empty())
        Distances.clear();

    Previous.resize(NumberOfVertices,-1);
    Distances.resize(NumberOfVertices, 10000);
}

void ListGraph::randomConection(std::vector<std::pair<int, int>>& possibleEdges, int NumberOfEdges)
{
    for (int i = 0; i < NumberOfEdges; ++i)
    {
        int edgeIndex = std::rand() % possibleEdges.size();
        int weight = std::rand() % 10 +1;//dodaje jeden aby waga nie wynosi³a 0
       


        std::pair<int, int> temp = possibleEdges[edgeIndex];
        auto removeIndex = possibleEdges.begin() + edgeIndex;
        possibleEdges.erase(removeIndex);
        addVertex(temp.first, temp.second, weight);
        
    }

    //std::cout << Adjacency.size();

    /*for (int i=0;i<Adjacency.size();i++){
        std::cout << i << " ->";
      for (int j = 0; j < Adjacency[i].size(); j++) {
          std::cout<< Adjacency[i][j].first << " "<<"("<< Adjacency[i][j].second << ") ";
      }
      std::cout << std::endl;
    }*/
}

typedef std::pair<int, int> Pair;

void ListGraph::dijkstra()
{
    std::priority_queue< Pair, std::vector<Pair>, std::greater<Pair> > pq;
    pq.push(std::make_pair(0, StartingVertex));
    Distances[StartingVertex] = 0;
   
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (!Adjacency[u].empty())
        {
            for (Pair neighbour : Adjacency[u])
            {
                int v = neighbour.first;
                int weight = neighbour.second;

                if (Distances[v] > Distances[u] + weight)
                {
                    Distances[v] = Distances[u] + weight;
                    
                    pq.push(std::make_pair(Distances[v], v));
                    
                    Previous[v] = u;
                    
                }
            }
        }
    }
}

void ListGraph::PrintDijkstra()
{
    std::cout << "vertex   distance from source" << std::endl;
    for (int i = 0; i < NumberOfVertices; ++i)
        std::cout << i << '\t' << '\t' << Distances[i] << std::endl;
    for (int i = 0; i < NumberOfVertices; ++i)
        std::cout << Previous[i] << ' ';
    std::cout << std::endl;
}

void ListGraph::LoadFromFile(std::string filename) {
    std::fstream file;
    file.open(filename);
    if (!file) {
        std::cerr << "File not opened\n";
        return;
    }
    file >> forFileNumberOfEdges;
    file >> NumberOfVertices;
    file >> StartingVertex;
    this->initializeAdjacency();
    int vertex;
    int neighbour;
    int weigth;
    while (file >> vertex) {
        file >> neighbour;
        file >> weigth;
        this->addVertex(vertex, neighbour, weigth);
    }
    file.close();
    dijkstra();
}