#include "MatrixGraph.h"
#include <iostream>
#include <queue>
#include <fstream>

MatrixGraph::MatrixGraph(int Vertices, int start)
{
    NumberOfVertices = Vertices;
    StartingVertex = start;
    Adjacency.resize(NumberOfVertices);

    for (int i = 0 ; i < NumberOfVertices ; i++)
    {
        Adjacency[i].resize(NumberOfVertices,10000);
    }
    
}

void MatrixGraph::addVertex(int vertex, int neighbour, int weight)
{
    Adjacency[vertex][neighbour] = weight;
}

void MatrixGraph::initializeAdjacency()
{
    if (!Adjacency.empty())
        Adjacency.clear();

    Adjacency.resize(NumberOfVertices);
    for (int i = 0; i < NumberOfVertices; i++)
    {
        Adjacency[i].resize(NumberOfVertices,10000);
    }

    if (!Previous.empty())
        Previous.clear();

    if (!Distances.empty())
        Distances.clear();

    Previous.resize(NumberOfVertices,-1);
    Distances.resize(NumberOfVertices, 10000);
    
}


void MatrixGraph::randomConection(std::vector<std::pair<int, int>>& possibleEdges, int NumberOfEdges)
{
    for (int i = 0; i < NumberOfEdges; ++i)
    {
        int weight = std::rand() % 9 + 1;
        int edgeIndex = std::rand() % possibleEdges.size();


        std::pair<int,int> temp = possibleEdges[edgeIndex];
        auto removeIndex = possibleEdges.begin() + edgeIndex;
        possibleEdges.erase(removeIndex);
        addVertex(temp.first, temp.second, weight);
    }
   /* for (int i = 0; i < Adjacency.size(); i++) {
        
        for (int j = 0; j < Adjacency[i].size(); j++) {
            std::cout << Adjacency[i][j] << " " ;
        }
        std::cout << std::endl;
    }*/
}

typedef std::pair<int, int> Pair;
void MatrixGraph::dijkstra()
{
    std::priority_queue< Pair, std::vector<Pair>, std::greater<Pair> > pq;
    pq.push(std::make_pair(0, StartingVertex));
    Distances[StartingVertex] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (!Adjacency.empty())
        {
            for (int neighbour = 0; neighbour < NumberOfVertices; neighbour++)
            {
                int v = neighbour;
                int weight = Adjacency[u][neighbour];


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

void MatrixGraph::PrintDijkstra()
{
    std::cout << "vertex   distance from source" << std::endl;
    for (int i = 0; i < NumberOfVertices; ++i)
        std::cout << i << '\t' << '\t' << Distances[i] << std::endl;
    for (int i = 0; i < NumberOfVertices; ++i)
        std::cout << Previous[i] << ' ';
    std::cout << std::endl;
}


void MatrixGraph::LoadFromFile(std::string filename) {
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