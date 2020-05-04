#include "Test.h"
#include <iostream>


/****************************
PREZENTOWANY GRAF JEST JEDNOKIERUNKOWY ABY TO ZMIENIC
ODKOMENTUJ LINIJKI W FUNKCJI addVector ORAZ PODZIEL 
WARTOSC NumberOfEdges PRZEZ 2
W FUNKCJI GenerateRandomGraph
*******************************/
int main()
{
    int choice = 1;
    string plik = "graf.txt";
    std::cout << "Dokonaj wyboru wpisujac przypisana cyfre do danej opcji:" << std::endl;
    while (choice == 1 || choice == 2)
    {
        std::cout << "******************************************" << std::endl;
        std::cout << "1.Test algortymu" << std::endl << "2.Wczytywanie z pliku" << std::endl << "3.Kazdy inny input konczy program" << std::endl;
        std::cin >> choice;

        while (std::cin.fail())
        {
            std::cout << "Blad wpisz ponownie" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000000, '\n');
            std::cin >> choice;
        }

        if (choice == 2)
        {
            ListGraph* g = new ListGraph();
            MatrixGraph* g2 = new MatrixGraph();
            g->LoadFromFile(plik);
            g2->LoadFromFile(plik);
            g->PrintDijkstra();
            g2->PrintDijkstra();
            delete g;
            delete g2;
        }
        else if (choice == 1)
        {
            Test Tescik;
            Tescik.TestDijkstra();
        }
        else
            exit(1);
    }
      
  
    //g->initializeAdjacency();
   //g2->initializeAdjacency();
    //g->addVertex(0, 1, 4);
    //g->addVertex(0, 7, 8);
    //g->addVertex(1, 2, 8);
    //g->addVertex(1, 7, 11);
    //g->addVertex(2, 3, 7);
    //g->addVertex(2, 8, 2);
    //g->addVertex(2, 5, 4);
    //g->addVertex(3, 4, 9);
    //g->addVertex(3, 5, 14);
    //g->addVertex(4, 5, 10);
    //g->addVertex(5, 6, 2);
    //g->addVertex(6, 7, 1);
    //g->addVertex(6, 8, 6);
    //g->addVertex(7, 8, 7);

    //g2->addVertex(0, 1, 4);
    //g2->addVertex(0, 7, 8);
    //g2->addVertex(1, 2, 8);
    //g2->addVertex(1, 7, 11);
    //g2->addVertex(2, 3, 7);
    //g2->addVertex(2, 8, 2);
    //g2->addVertex(2, 5, 4);
    //g2->addVertex(3, 4, 9);
    //g2->addVertex(3, 5, 14);
    //g2->addVertex(4, 5, 10);
    //g2->addVertex(5, 6, 2);
    //g2->addVertex(6, 7, 1);
    //g2->addVertex(6, 8, 6);
    //g2->addVertex(7, 8, 7);
    //std::cout << std::endl;
    //g->dijkstra();
    //std::cout << std::endl;
    //g2->dijkstra();

    //delete g;
    //delete g2;
    
    

}

