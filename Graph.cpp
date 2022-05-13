//
// Created by Utilizador on 12/05/2022.
//

#include <cmath>
#include "Graph.h"


template<class T>
Graph<T>::Graph(bool isDir) {
    this->dir = isDir;
    this->allNodes = {};
}

template<class T>
bool Graph<T>::operator==(Graph<T> A) {
    return this->allNodes == A.allNodes;
}

template<class T>
unsigned int Graph<T>::addNode(T value) {
    Node<T> newNode;

    newNode.value = value;
    newNode.visited = false;
    newNode.adj = {};
    newNode.id = idCounter++;

    allNodes.push_back(newNode);
    return newNode.id;
}

template<class T>
bool Graph<T>::removeNode(unsigned int idNode) {
    int high = allNodes.size() -1;
    unsigned int low = 0;

    while (low <= high) {
        unsigned int mid = low + (high - low) / 2;

        if (allNodes.at(mid).id == idNode) {
            allNodes.erase(allNodes.begin() + mid);
            return true;
        }
        else if (allNodes.at(mid).id < idNode)
            low = mid + 1;
        else if (idNode < allNodes.at(mid).id)
            high = mid - 1;
    }
    return false;
}

template<class T>
void Graph<T>::setAllNotVisited() {
    for (Node<T> node : allNodes){
        node.visited = false;
    }
    return;
}

template<class T>
std::vector<Node<T>> Graph<T>::getAllNodes() const {
    return allNodes;
}

template<class T>
std::vector<Node<T>> Graph<T>::getAllNodesPtr() const {
    std::vector<Node<T>> allNodesPtr;
    for (Node<T> node : allNodes){
        allNodesPtr.push_back(&node);
    }
    return allNodesPtr;
}

template<class T>
unsigned int Graph<T>::size() {
    return allNodes.size();
}

template<class T>
unsigned int Graph<T>::findNodeIndex(T value) {
    for (unsigned int idx; idx < allNodes.size(); ++idx){
        if (allNodes.at(idx).value == value) return idx;
    }
    return INT_MAX;
}

