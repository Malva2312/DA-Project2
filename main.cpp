#include <iostream>
#include "classes/Graph.h"
#include "classes/FileReader.h"
#include "classes/App.h"

void print_allPaths(vector<pair<unsigned int, stack<Edge<int> *>>> allPaths);

int main() {


    string filename = "../Tests/in02.txt";

    Graph<int> test = Graph<int>();
    FileReader fileReader(filename);
    fileReader.initGraph(&test);

    unsigned int start = test.getAllNodes().at(0).value -1;
    unsigned int end = test.size() -1;

    /*
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
*/
    vector<pair<unsigned int, stack<Edge<int> *>>> allPaths;

    int max = test.edmondsKarp(start, end);
    max = 2;
    cout << "max flow of the graph: "<< max  << endl;

    cout <<  test.scenario2_1(max, start, end, allPaths) << " free space" << endl;
    print_allPaths(allPaths);
    cout <<endl;

    cout << "max flow of the graph: "<< max  << endl;
    cout <<  test.scenario2_1(max, start, end, allPaths) << " free space" << endl;
    print_allPaths(allPaths);
    cout << endl;

   //cout << test.scenario2_4(max, start, end) << endl;
/*
    App app;
    return app.run();
*/

    return 0;
}

void print_allPaths(vector<pair<unsigned int, stack<Edge<int> *>>> allPaths){

    for (auto & allPath : allPaths)
    {
        cout << allPath.first << " of flow :\t";
        while (allPath.second.size()>1){

            cout << allPath.second.top()->prev->value << "\t->\t";
            allPath.second.pop();
        }
        cout << allPath.second.top()->prev->value << "\t->\t";
        cout << allPath.second.top()->next->value << endl;
    }

}
