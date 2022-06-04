//
// Created by Utilizador on 12/05/2022.
//

#ifndef DA_PROJECT2_GRAPH_H
#define DA_PROJECT2_GRAPH_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>
#include <map>
#include "MaxHeap.h"
#include <stack>

template <class T> struct Edge;
template <class T> struct Node;
template <class T> class Graph;

template <class T>
struct Node{
    std::vector<Edge<T>> adj;
    unsigned int id;
    bool visited;
    T value;

    /* needed to calculate maximum capacity*/
    Node<T> * parent;  //parent
    Edge<T> * parentEdge;

    unsigned int capacity; // capacity: parent -> this

};

template <class T>
struct Edge{
    unsigned int  weight = 0;
    int duration = 0;
    Node<T> * next; //next

    Node<T> * prev; //previous

    bool used = false;
    unsigned int flow = 0;

    //used on edmond //chek if the flow is returning
    std::pair<Edge<T> *, bool> dir;
};

template <class T>
class Graph {
private:
    std::vector<Node<T>> allNodes;
    unsigned int idCounter = 1;
    //bool dir;
public:
    Graph();
    bool operator== (Graph<T> A);
    unsigned int addNode(T value); //adicionar um node com um valor
    //bool removeNode(unsigned int value); //remover um node pelo seu index
    void setAllNotVisited(); //todos os nodes não visitados
    void setAllParentNull();
    std::vector<Node<T>> getAllNodes() const; //recebe o vetor dos nodes
    std::vector<Node<T>*> getAllNodesPtr(); //recebe um vetor com Ptr dos nodes
    unsigned int size() const; //numero de nodes
    unsigned int findNodeIndex(unsigned int idNode);
    unsigned int addEdge(unsigned int idxStart, unsigned int idxEnd, int weight, int duration = 0); //adiciona edge de start -> end se for dir// se !dir adiciona start<->end
    //bool eraseEdge(unsigned int start, unsigned int end, int weight);//elimina edge de start -> end se for dir// se !dir elimina start<->end
    std::vector<Node<T> * > BFS(Graph<T> &G,  unsigned int idxStartNode);//vetor com os idx ordenados pela ordem que são encontrados na BFS

    void maxCapacity(unsigned int startIdx);
    unsigned int edmondsKarp(unsigned int idxStart, unsigned int idxEnd); //
    Graph<T> updateRGraph(Graph<T> &G);
    unsigned int scenario2_1(unsigned int size, unsigned int start, unsigned int finish,
                             std::vector<std::pair<unsigned int, std::stack<Edge<T> *>>> &solution = {});  //flow maximo permitido no caminho, stack das edges do caminho

    //Graph<T> minimumChanges(unsigned int idxStart, unsigned int idxEnd);
    //std::vector<Edge<T> *> smallWayMaxCap(Graph<T> &G, unsigned int startIdx, unsigned int endIdx, unsigned int maxDist, unsigned int dist = 0);
    void setAllNotUsed();


};

#endif //DA_PROJECT2_GRAPH_H
