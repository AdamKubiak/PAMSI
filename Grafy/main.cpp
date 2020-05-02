#include "ListGraph.h"
#include "MatrixGraph.h"
#include <iostream>

int main()
{
    ListGraph* g = new ListGraph(14,0);
    MatrixGraph* g2 = new MatrixGraph(14,0);
    g->initializeAdjacency();
    g2->initializeAdjacency();

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

    g2->addVertex(0, 1, 4);
    g2->addVertex(0, 7, 8);
    g2->addVertex(1, 2, 8);
    g2->addVertex(1, 7, 11);
    g2->addVertex(2, 3, 7);
    g2->addVertex(2, 8, 2);
    g2->addVertex(2, 5, 4);
    g2->addVertex(3, 4, 9);
    g2->addVertex(3, 5, 14);
    g2->addVertex(4, 5, 10);
    g2->addVertex(5, 6, 2);
    g2->addVertex(6, 7, 1);
    g2->addVertex(6, 8, 6);
    g2->addVertex(7, 8, 7);
    
    std::cout << std::endl;
    g->dijkstra();
    std::cout << std::endl;
    g2->dijkstra();

   std:: cout << "SMIGA!!!!" <<std:: endl;

    delete g;
    delete g2;
    
    

}

