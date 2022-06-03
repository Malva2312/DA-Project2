#include <iostream>
#include "classes/Graph.h"
#include "classes/FileReader.h"
#include "classes/App.h"

int main() {


    string filename = "../Tests/in10.txt";
    int dest = 5000;
    /*
    Graph<int> test = Graph<int>();
    FileReader fileReader(filename);
    fileReader.initGraph(&test);
    */
    Graph<int> test = Graph<int>();
    test.addNode(0);
    test.addNode(1);
    test.addNode(2);

    test.addNode(3);
    test.addNode(4);
    test.addNode(5);

    test.addNode(6);

    test.addEdge(0 , 1 ,  100, 0);
    test.addEdge(0 , 2 ,  100, 0);
    test.addEdge(1 , 3 ,  4, 0);
    test.addEdge(1 , 4 ,  5, 0);
    test.addEdge(2 , 1 ,  3, 0);
    test.addEdge(2 , 4 ,  6, 0);
    test.addEdge(2 , 5 ,  7, 0);
    test.addEdge(3 , 6 , 10, 0);
    test.addEdge(4 , 6 ,  9, 0);
    test.addEdge(5 , 6 ,  1, 0);
    test.addEdge(6 , 0 , 30, 0);
/*
    App app;
    return app.run();
*/
    return 0;
}
