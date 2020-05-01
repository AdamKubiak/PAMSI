#include "ListGraph.h"
#include "MatrixGraph.h"
#include <iostream>

int main()
{
    std::unique_ptr<Graph> graph1;
    std::unique_ptr<Graph> graph2;
    graph1 = std::make_unique<ListGraph>();
    graph2 = std::make_unique<MatrixGraph>();
    graph1->GenerateRandomGraph(10, 0.5);
    std::cout << std::endl;
    graph2->GenerateRandomGraph(10, 1);
    
    

}

