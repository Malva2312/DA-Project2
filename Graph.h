//
// Created by Utilizador on 12/05/2022.
//

#ifndef DA_PROJECT2_GRAPH_H
#define DA_PROJECT2_GRAPH_H

#include <vector>

template <class T> struct Edge;
template <class T> struct Node;
template <class T> class Graph;

template <class T>
struct Node{
    std::vector<T> adj;
    unsigned int id;
    bool visited;
    T value;
};

template <class T>
struct Edge{
    unsigned int weight;
    Node<T> * next;
    bool used;
};

template <class T>
class Graph {
private:
    std::vector<Node<T>> allNodes;
    bool dir{};
    unsigned int idCounter = 0;
public:
    Graph(bool isDir); // se o graph é dirigido
    bool operator== (Graph<T> A); // para atribuir uma cópia do graph
    unsigned int addNode(T idNode); //adicionar um node com um valor
    bool removeNode(unsigned int value); //remover um node pelo seu index
    void setAllNotVisited(); //todos os nodes não visitados
    std::vector<Node<T>> getAllNodes() const; //recebe o vetor dos nodes
    std::vector<Node<T>> getAllNodesPtr() const; //recebe um vetor com Ptr dos nodes
    unsigned int size(); //numero de nodes
    unsigned int findNodeIndex(T value); //recebe um valor de um nó, retorna a sua posição
    void addEdge(unsigned int idStart, unsigned int idEnd, int weight); //adiciona edge de start -> end se for dir// se !dir adiciona start<->end
    void eraseEdge(unsigned int start, unsigned int end, int weight);//elimina edge de start -> end se for dir// se !dir elimina start<->end
    std::vector<unsigned int> BFS(unsigned int idxStartNode);//vetor com os idx ordenados pela ordem que são encontrados na BFS

};

#endif //DA_PROJECT2_GRAPH_H
