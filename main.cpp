#include <iostream>
#include "Graph.cpp"


int main() {
    std::cout << "Hello, World!" << std::endl;

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
    return 0;
}
