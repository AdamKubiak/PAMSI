#include "MatrixGraph.h"
#include <iostream>
#include <climits>
#include <queue>
#include <algorithm>
#include <iostream>
MatrixGraph::MatrixGraph(int Vertices, int start)
{
    Adjacency.resize(NumberOfVertices);

    for (int i = 0 ; i < NumberOfVertices ; i++)
    {
        Adjacency[i].resize(NumberOfVertices);
    }
   
}


void MatrixGraph::initializeAdjacency()
{
    if (!Adjacency.empty())
        Adjacency.clear();

    Adjacency.resize(NumberOfVertices);
    for (int i = 0; i < NumberOfVertices; i++)
    {
        Adjacency[i].resize(NumberOfVertices);
    }
    
}


void MatrixGraph::randomConection(std::vector<std::pair<int, int>>& possibleEdges, int NumberOfEdges)
{
    for (int i = 0; i < NumberOfEdges; ++i)
    {
        int cost = std::rand() % 9 + 1;
        int edgeIndex = std::rand() % possibleEdges.size();


        std::pair<int,int> temp = possibleEdges[edgeIndex];
        auto toRemove = possibleEdges.begin() + edgeIndex;
        possibleEdges.erase(toRemove);
        Adjacency[temp.first][temp.second] = cost;
        Adjacency[temp.second][temp.first] = cost;
    }
    for (int i = 0; i < Adjacency.size(); i++) {
        
        for (int j = 0; j < Adjacency[i].size(); j++) {
            std::cout << Adjacency[i][j] << " " ;
        }
        std::cout << std::endl;
    }
}

/*typedef std::pair<int, int> Pair;
void MatrixGraph::dijkstra()
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
            for (int neighbour : Adjacency[u])
            {
                int v = neighbour.first;
                int weight = neighbour.second;

                if (Distances[v] > Distances[u] + weight)
                {
                    Distances[v] = Distances[u] + weight;

                    pq.push(std::make_pair(Distances[v], v));

                    // Previous[v] = u;

                }
            }
        }

    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < NumberOfVertices; ++i)
        printf("%d \t\t %d\n", i, Distances[i]);
}*/