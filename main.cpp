#include <iostream>
#include "Graph.cpp"
#include "FileReader.h"


int main() {
    Graph<int> test = Graph<int>();
    FileReader fileReader;
    fileReader.initGraph(&test);
    for (int i=0;i<test.getAllNodes().size();i++){
        //cout<<test.getAllNodes()[i].id<<endl;
        for (int j=0;j<test.getAllNodes()[i].adj.size();j++){
            cout<<"next id: "<<test.getAllNodes()[i].adj[j].next->id<<" capacity: "<<test.getAllNodes()[i].adj[j].weight<<" duration: "<< test.getAllNodes()[i].adj[j].duration<<endl;
        }
    }
    /*
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


    auto foo = test.BFS(0);
    for (int boo : foo){
        std::cout << boo << std::endl;
    }
     */
    return 0;
}
