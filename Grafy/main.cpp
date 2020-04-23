#include "ListGraph.h"

#include <iostream>
#include <fstream>
#include <memory>

int main()
{
    std::unique_ptr<Graph> graph;
    graph = std::make_unique<ListGraph>();

    graph->GenerateRandomGraph(6, 1);
    
    

}

