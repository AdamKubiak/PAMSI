#include "ListGraph.h"
#include "MatrixGraph.h"
#include <iostream>

int main()
{
    ListGraph* g = new ListGraph(14,0);
    //MatrixGraph* graph2 = new MatrixGraph();
    //g->GenerateRandomGraph(9, 1);
    g->initializeAdjacency();
    g->addVertex(0, 1, 4);
    g->addVertex(0, 7, 8);
    g->addVertex(1, 2, 8);
    g->addVertex(1, 7, 11);
    g->addVertex(2, 3, 7);
    g->addVertex(2, 8, 2);
    g->addVertex(2, 5, 4);
    g->addVertex(3, 4, 9);
    g->addVertex(3, 5, 14);
    g->addVertex(4, 5, 10);
    g->addVertex(5, 6, 2);
    g->addVertex(6, 7, 1);
    g->addVertex(6, 8, 6);
    g->addVertex(7, 8, 7);
    
    std::cout << std::endl;
   // graph2->GenerateRandomGraph(10, 0->5);
    std::cout << std::endl;
    g->dijkstra();
    std::cout << std::endl;
   // graph2->dijkstra();

    
    

}

