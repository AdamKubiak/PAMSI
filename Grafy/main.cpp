#include "ListGraph.h"

#include <iostream>

int main()
{
    std::unique_ptr<Graph> graph;
    graph = std::make_unique<ListGraph>();

    graph->GenerateRandomGraph(10, 0.5);
    
    
    

}

