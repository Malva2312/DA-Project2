//
// Created by Utilizador on 12/05/2022.
//

#include <queue>
#include "Graph.h"



Graph::Graph() {
    this->allNodes = {};
}


bool Graph::operator==(Graph A) {
    return this->allNodes == A.allNodes;
}


unsigned int Graph::addNode(int id) {
    Node newNode;

    newNode.visited = false;
    newNode.adj = {};
    newNode.id = idCounter++;

    allNodes.push_back(newNode);
    return newNode.id;
}


bool Graph::removeNode(unsigned int idNode) {
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


void Graph::setAllNotVisited() {
    for (Node node : allNodes){
        node.visited = false;
    }
    return;
}


std::vector<Node> Graph::getAllNodes() const {
    return allNodes;
}


std::vector<Node> Graph::getAllNodesPtr() const {
    std::vector<Node> allNodesPtr;
    for (Node node : allNodes){
        allNodesPtr.push_back(node);
    }
    return allNodesPtr;
}


unsigned int Graph::size() {
    return allNodes.size();
}


unsigned int Graph::findNodeIndex(int id) {
    for (unsigned int idx; idx < allNodes.size(); ++idx){
        if (allNodes.at(idx).id == id) return idx;
    }
    return INT_MAX;
}


void Graph::addEdge(unsigned int idStart, unsigned int idEnd, int weight) {
    Edge newEdge;

    newEdge.weight = weight;
    newEdge.next = &(allNodes.at(idEnd));
    newEdge.used = false;

    allNodes.at(idStart).adj.push_back(newEdge);
}



std::vector<unsigned int> Graph::BFS(unsigned int idxStartNode) {
    setAllNotVisited();

    std::queue<unsigned int> nodesIdQueue;
    std::vector<unsigned int> idPath = {idxStartNode};

    allNodes.at(idxStartNode).visited = true;
    fadd;
}

