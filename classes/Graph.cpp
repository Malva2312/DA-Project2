//
// Created by Utilizador on 12/05/2022.
//

#include "Graph.h"


template<class T>
Graph<T>::Graph() {
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
    int pos = findNodeIndex(idNode);
    allNodes.erase(allNodes.begin() + pos);
    return true;
}

template<class T>
void Graph<T>::setAllNotVisited() {
    for (Node<T> node : allNodes){
        node.visited = false;
    }
}

template<class T>
std::vector<Node<T>> Graph<T>::getAllNodes() const {
    return allNodes;
}

template<class T>
std::vector<Node<T> *> Graph<T>::getAllNodesPtr() {
    std::vector<Node<T>*> allNodesPtr;
    for (unsigned int idx = 0; idx < size(); idx++){
        allNodesPtr.push_back(&allNodes.at(idx));
    }
    return allNodesPtr;
}

template<class T>
unsigned int Graph<T>::size() const{
    return allNodes.size();
}

/*
template<class T>
unsigned int Graph<T>::findNodeIndex(T value) {
    for (unsigned int idx; idx < allNodes.size(); ++idx){
        if (allNodes.at(idx).value == value) return idx;
    }
    return INT_MAX;
}*/

template<class T>
unsigned int Graph<T>::findNodeIndex(unsigned int idNode) {
    int high = allNodes.size() -1;
    unsigned int low = 0;

    while (low <= high) {
        unsigned int mid = low + (high - low) / 2;

        if (allNodes.at(mid).id == idNode) {
            return mid;
        }
        else if (allNodes.at(mid).id < idNode)
            low = mid + 1;
        else if (idNode < allNodes.at(mid).id)
            high = mid - 1;
    }
    return INT_MAX;
}

template<class T>
void Graph<T>::addEdge(unsigned int idxStart, unsigned int idxEnd, int weight, int duration) {
    Edge<T> newEdge;

    newEdge.duration = duration;
    newEdge.weight = weight;
    newEdge.next = &(allNodes.at(idxEnd));
    newEdge.prev = &(allNodes.at(idxStart));
    newEdge.used = false;
    allNodes.at(idxStart).adj.push_back(newEdge);
}

template<class T>
bool Graph<T>::eraseEdge(unsigned int start, unsigned int end, int weight) {
    for (int i = 0; i < allNodes.size(); i++)
    {
        if(allNodes.at(i).weight == weight){
            erase(allNodes.at(i).begin + i);
            return true;
        }
    }
    return false;
}

template<class T>
std::vector<Node<T> * > Graph<T>::BFS(unsigned int idxNode) {

    setAllNotVisited();

    std::queue<Node<T> *> nodesQueue;
    nodesQueue.push(&allNodes.at(idxNode));
    std::vector<Node<T>*> path;

    allNodes.at(idxNode).visited = true;

    Node<T> * node;
    while (!nodesQueue.empty()){

        node = nodesQueue.front();
        nodesQueue.pop();

        for (Edge<T> edge : node->adj){

            if (edge.next->visited == false)
            {
                edge.next->visited = true;
                nodesQueue.push(edge.next);
            }
        }
        path.push_back(node);
    }
    return path;
}

template<class T>
void Graph<T>::maxCapacity(unsigned int startIdx) {
    //unsigned int idx = findNodeIndex(startId);

    for (unsigned int i = 0; i < allNodes.size(); i++)
    {
        allNodes.at(i).parent = nullptr;
        allNodes.at(i).capacity = 0;
    }

    allNodes.at(startIdx).capacity = INT_MAX;

    maxHeap<Node<T> *> pQueue;
    pQueue.push(
            allNodes.at(startIdx).capacity,
            &allNodes.at(startIdx)
            );

    //std::vector<>

    while (!pQueue.empty()){

        std::pair<int, Node<T>*> node = pQueue.top();
        pQueue.pop();

        for (Edge<T> edge : node.second->adj){
            unsigned int cap = std::min( (unsigned int) node.second->capacity, edge.weight);
            if (cap > edge.next->capacity ){
                edge.next->capacity = cap;
                edge.next->parent = node.second;
                pQueue.push(
                        cap,
                        edge.next
                );
            }
        }
    }

}

template<class T>
Graph<T> Graph<T>::updateRGraph(Graph<T> G) {
    Graph<T> Gr; //residual graph

    for (unsigned int idx = 0; idx < size(); idx)
    {
        Gr.addNode(G.getAllNodesPtr()->at(idx).value);
        Gr.getAllNodesPtr().at(idx).id = G.getAllNodesPtr().at(idx).id;
    }

    for (unsigned int idx = 0; idx < size(); idx++)
    {
        for (unsigned int edge = 0; edge < G.getAllNodesPtr()->at(idx).adj.size(); edge++)
        {
            unsigned int flow = G.getAllNodesPtr().at(idx).adj.at(edge).flow;
            unsigned int cap = G.getAllNodesPtr().at(idx).adj.at(edge).weight;
            if (flow < cap){
                //residual
                Gr.addEdge(
                        G.getAllNodesPtr().at(idx).id,
                        G.getAllNodesPtr().at(idx).adj.at(edge).next->id,
                        cap - flow);
            }
            if (flow > 0){
                //residual
                addEdge(
                        G.getAllNodesPtr().at(idx).adj.at(edge).next->id,
                        G.getAllNodesPtr().at(idx).id,
                        flow);
            }
        }
    }
    return  Gr;

}


template<class T>
void Graph<T>::fordFulkerson(unsigned int idxStart, unsigned int idxEnd) {
    for (unsigned int idx = 0; idx < size(); idx++)
    {
        for (unsigned int edge = 0; edge < allNodes.at(idx).adj.size(); edge++)
        {
            allNodes.at(idx).adj.at(edge).flow = 0;
        }
    }

    Graph<T> Gr = updateRGraph(this);
/*
    while (f)
    {

    }
*/
    //Graph::Graph<T>
}

template<class T>
void Graph<T>::increasePath(Graph<T> &Gr, unsigned int idx) {

    return ;
}


