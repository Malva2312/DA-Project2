#include <iostream>
#include "classes/Graph.h"
#include "classes/FileReader.h"


int main() {
    /*
    Graph<int> test = Graph<int>();
    FileReader fileReader;
    fileReader.initGraph(&test);
    for (int i=0;i<test.getAllNodes().size();i++){
        //cout<<test.getAllNodes()[i].id<<endl;
        for (int j=0;j<test.getAllNodes()[i].adj.size();j++){
            cout<<"next id: "<<test.getAllNodes()[i].adj[j].next->id<<" capacity: "<<test.getAllNodes()[i].adj[j].weight<<" duration: "<< test.getAllNodes()[i].adj[j].duration<<endl;
        }
    }
     */

    Graph<int> test = Graph<int>();
    test.addNode(0);
    test.addNode(1);
    test.addNode(2);

    test.addNode(3);
    test.addNode(4);
    test.addNode(5);

    test.addNode(6);
    test.addNode(7);
    test.addNode(8);

    test.addNode(9);
    test.addNode(10);
    test.addNode(11);

    test.addEdge(0 , 1 , 0, 0);
    test.addEdge(0 , 2 , 0, 0);
    test.addEdge(1 , 2 , 0, 0);
    test.addEdge(2 , 3 , 0, 0);
    test.addEdge(3 , 4 , 0, 0);
    test.addEdge(4 , 5 , 0, 0);
    test.addEdge(0 , 6 , 0, 0);

    for (Node<int>* boo : test.BFS(0)){
        std::cout << boo->value << std::endl;
    }

    return 0;
}
