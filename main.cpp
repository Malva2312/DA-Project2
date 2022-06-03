#include <iostream>
#include "classes/Graph.h"
#include "classes/FileReader.h"
#include "classes/App.h"

int main() {
/*
    string filename = "../Tests/in01.txt";
    int dest = 50;


    Graph<int> test = Graph<int>();
    FileReader fileReader(filename);
    fileReader.initGraph(&test);
    /*
    for (int i=0;i<test.getAllNodes().size();i++){
        //cout<<test.getAllNodes()[i].id<<endl;
        for (int j=0;j<test.getAllNodes()[i].adj.size();j++){
            cout<<"next id: "<<test.getAllNodes()[i].adj[j].next->id<<" capacity: "<<test.getAllNodes()[i].adj[j].weight<<" duration: "<< test.getAllNodes()[i].adj[j].duration<<endl;
        }
    }

    for (auto node : test.getAllNodes()){
        if (node.parent == nullptr && node.capacity == INT_MAX){
            cout << "origin  " << node.capacity << endl;
        }
        else if (node.parent == nullptr){
            continue;
        }
        else cout << node.parent->value << "  "<< node.capacity <<endl;
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

    test.addEdge(0 , 1 ,  1, 0);
    test.addEdge(0 , 2 ,  2, 0);
    test.addEdge(1 , 3 ,  4, 0);
    test.addEdge(1 , 4 ,  5, 0);
    test.addEdge(2 , 1 ,  3, 0);
    test.addEdge(2 , 4 ,  6, 0);
    test.addEdge(2 , 5 ,  7, 0);
    test.addEdge(3 , 6 , 10, 0);
    test.addEdge(4 , 6 ,  9, 0);
    test.addEdge(5 , 6 ,  8, 0);
    test.addEdge(6 , 0 , 30, 0);
/**/
    //test.BFS(test, 0);
    int idx = 6; //id 6, value 6
    Node<int> * n = test.getAllNodesPtr().at(idx);

    test.edmondsKarp(0, 6);

/*
    while (n->parentEdge != nullptr)
    {
        cout << n->value << " - ";
        n = n->parentEdge->prev;
    }
    cout << n->value;
*/
/*
    App app;
    return app.run();
*/
    return 0;
}
