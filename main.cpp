#include <iostream>
#include "classes/Graph.h"
#include "classes/FileReader.h"
#include "classes/maxHeap.h"


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
     /*
     test.addNode(7);
     test.addNode(8);

     test.addNode(9);
     test.addNode(10);
     test.addNode(11);
*/
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

    test.maxCapacity( 6);

    for (auto node : test.getAllNodes()){
        if (node.parent == nullptr && node.capacity == INT_MAX){
            cout << "origin  " << node.capacity << endl;
        }
        else if (node.parent == nullptr){
            continue;
        }
        else cout << node.parent->value << "  "<< node.capacity <<endl;
    }
    /*
    for (Node<int>* boo : test.BFS(1)){
        std::cout << boo->value << std::endl;
    }*/

    return 0;
}
