//
// Created by Utilizador on 12/05/2022.
//

#ifndef DA_PROJECT2_GRAPH_H
#define DA_PROJECT2_GRAPH_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
struct Edge;
struct Node;
class Graph;

struct Node{
    std::vector<Edge> adj;
    unsigned int id;
    bool visited;
};

struct Edge{
    unsigned int weight;
    Node * next;
    bool used;
};





class Graph {

private:
    std::vector<Node> allNodes;
    unsigned int idCounter = 0;
    //bool dir;
public:
    Graph(); // se o graph é dirigido
    bool operator== (Graph A);
    unsigned int addNode(int id); //adicionar um node com um valor
    bool removeNode(unsigned int value); //remover um node pelo seu index
    void setAllNotVisited(); //todos os nodes não visitados
    std::vector<Node> getAllNodes() const; //recebe o vetor dos nodes
    std::vector<Node> getAllNodesPtr() const; //recebe um vetor com Ptr dos nodes
    unsigned int size(); //numero de nodes
    unsigned int findNodeIndex(int id); //recebe um valor de um nó, retorna a sua posição
    void addEdge(unsigned int idStart,unsigned int idEnd, int weight); //adiciona edge de start -> end se for dir// se !dir adiciona start<->end
    std::vector<unsigned int> BFS(unsigned int idxStartNode);//vetor com os idx ordenados pela ordem que são encontrados na BFS

};

#endif //DA_PROJECT2_GRAPH_H
