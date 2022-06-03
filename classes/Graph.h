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
    unsigned int weight;
    int duration;
    Node<T> * next; //next

    Node<T> * prev; //previus

    //bool used;
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
    bool removeNode(unsigned int value); //remover um node pelo seu index
    void setAllNotVisited(); //todos os nodes não visitados
    void setAllParentNull();
    std::vector<Node<T>> getAllNodes() const; //recebe o vetor dos nodes
    std::vector<Node<T>*> getAllNodesPtr(); //recebe um vetor com Ptr dos nodes
    unsigned int size() const; //numero de nodes
    //unsigned int findNodeIndex(T value); //recebe um valor de um nó, retorna a sua posição
    unsigned int findNodeIndex(unsigned int idNode);
    unsigned int addEdge(unsigned int idxStart, unsigned int idxEnd, int weight, int duration = 0); //adiciona edge de start -> end se for dir// se !dir adiciona start<->end
    bool eraseEdge(unsigned int start, unsigned int end, int weight);//elimina edge de start -> end se for dir// se !dir elimina start<->end
    std::vector<Node<T> * > BFS(Graph<T> &G,  unsigned int idxStartNode);//vetor com os idx ordenados pela ordem que são encontrados na BFS

    void maxCapacity(unsigned int startIdx);
    unsigned int edmondsKarp(unsigned int idxStart, unsigned int idxEnd); //
    Graph<T> updateRGraph(Graph<T> &G);
    //void increasePath(Graph<T> &Gr, unsigned int idx); //BFS
};

#endif //DA_PROJECT2_GRAPH_H
