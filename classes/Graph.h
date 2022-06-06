//
// Created by Utilizador on 12/05/2022.
//

#ifndef DA_PROJECT2_GRAPH_H
#define DA_PROJECT2_GRAPH_H

#include <iostream>
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

    unsigned int capacity = 0; // capacity: parent -> this
    unsigned int waiting_first = INT_MAX;
    unsigned int waiting_last = 0;
};

template <class T>
struct Edge{
    unsigned int weight   = 0;
    unsigned int duration = 0;

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
    /**
     * BFS to determine a path with the least amount of nodes
     * @param G
     * @param idxStartNode
     * @return vector with the nodes of the path
     */
    std::vector<Node<T> * > BFS(Graph<T> &G,  unsigned int idxStartNode);//vetor com os idx ordenados pela ordem que são encontrados na BFS

    /**
     * Marks the nodes that do not have the max capacity as nullptr so that we can determine the path that has the maximum capacity possible given a starting point
     * @param startIdx
     */
    void maxCapacity(unsigned int startIdx);
    /**
     * Implements scenario 1_2 where it shows both the path with maximum capacity and the path with least nodes and tries to find a compromise between both while displaying every possibility as well as their capacity
     * @param startIdx
     * @param finishIdx
     * @param G1
     * @param G2
     */
    void scenario1_2(unsigned int startIdx,unsigned int finishIdx,Graph<T> &G1,Graph<T> &G2);

    /**
     * Edmonds Karp algorithm to determine the maximum flow
     * @param idxStart
     * @param idxEnd
     * @return returns the capacity of the end node
     */
    unsigned int edmondsKarp(unsigned int idxStart, unsigned int idxEnd); //

    /**
     * Creates a residual graph, used during the edmonds Karp algorithm
     * @param G
     * @return Returns the residual graph
     */
    Graph<T> updateRGraph(Graph<T> &G);

    /**
     * Implements scenario 2.1 by determining the maximum flow and calculating the best path with BFS and then tries to fill that path with the number of people given by the arg "size", if it cant,
     * repeats this process until every person has a path to go, by marking every edges of least flow as used
     * @param size
     * @param start
     * @param finish
     * @param solution
     * @return the amount of people that could still go in as part of the group
     */
    unsigned int scenario2_1(unsigned int size, unsigned int start, unsigned int finish,
                             std::vector<std::pair<unsigned int, std::stack<Edge<T> *>>> &solution = {});  //flow maximo permitido no caminho, stack das edges do caminho

                             /**
                              * Implements scenario 2.4 and 2.5 , given all the paths by the function that implements scenario 2.1 calculates how much time people from a group would have to wait to be
                              * reunited and also allows to calculate the maximum waiting time and the node where it happens by changing the variables waiting first and waiting last in the graph's nodes
                              * @param size
                              * @param start
                              * @param finish
                              * @param solution
                              * @return Returns the waiting time in the last node
                              */
    unsigned int scenario2_4(unsigned int size, unsigned int start, unsigned int finish,
                             std::vector<std::pair<unsigned int, std::stack<Edge<T> *>>> solution);
    //Graph<T> minimumChanges(unsigned int idxStart, unsigned int idxEnd);
    //std::vector<Edge<T> *> smallWayMaxCap(Graph<T> &G, unsigned int startIdx, unsigned int endIdx, unsigned int maxDist, unsigned int dist = 0);

    /**
     * Sets all edges as unused
     */
    void setAllNotUsed();

    /**
     * Sets the waiting time to 0
     */
    void setTimeTo0();


};

#endif //DA_PROJECT2_GRAPH_H
