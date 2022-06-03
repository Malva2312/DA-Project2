#include <iostream>
#include "classes/Graph.h"
#include "classes/FileReader.h"
#include "classes/App.h"

int main() {

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




    cout << test.edmondsKarp(0, 49) << endl;

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
