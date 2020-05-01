#include "ListGraph.h"
#include "MatrixGraph.h"
#include <iostream>

int main()
{
    ListGraph* graph1 = new ListGraph();
    MatrixGraph* graph2 = new MatrixGraph();
    graph1->GenerateRandomGraph(10, 0.5);
    
    std::cout << std::endl;
    graph2->GenerateRandomGraph(10, 0.5);
   // graph1->dijkstra();
    
    

}

