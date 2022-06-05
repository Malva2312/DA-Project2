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
/*
template<class T>
bool Graph<T>::removeNode(unsigned int idNode) {
    int pos = findNodeIndex(idNode);
    allNodes.erase(allNodes.begin() + pos);
    return true;
}
*/
template<class T>
void Graph<T>::setAllNotVisited() {
    for (Node<T> * node : getAllNodesPtr()){
        node->visited = false;
    }
}

template<class T>
void Graph<T>::setAllNotUsed(){
    for (Node<T> node : allNodes){
        for (unsigned int edge = 0; edge < node.adj.size(); edge++){
            node.adj.at(edge).used = false;
        }
    }
}

template<class T>
void Graph<T>::setTimeTo0(){
    for (Node<T> & node : allNodes){
        node.waiting = 0;
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
    unsigned int high = allNodes.size() -1;
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
unsigned int Graph<T>::addEdge(unsigned int idxStart, unsigned int idxEnd, int weight, int duration) {
    Edge<T> newEdge;

    newEdge.duration = duration;
    newEdge.weight = weight;
    newEdge.next = &(allNodes.at(idxEnd));
    newEdge.prev = &(allNodes.at(idxStart));
    //newEdge.used = false;
    allNodes.at(idxStart).adj.push_back(newEdge);

    unsigned int pos = allNodes.at(idxStart).adj.size() -1;
    allNodes.at(idxStart).adj.at(pos).dir.first = nullptr;
    allNodes.at(idxStart).adj.at(pos).dir.second = true;

    return pos;
}
/*
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
 */

template<class T>
std::vector<Node<T> * > Graph<T>::BFS(Graph<T> &G, unsigned int idxNode) {

    G.setAllNotVisited();
    G.setAllParentNull();

    std::queue<Node<T> *> nodesQueue;
    std::vector<Node<T> *> Nodes = G.getAllNodesPtr();

    nodesQueue.push(Nodes.at(idxNode));
    std::vector<Node<T>*> order;

    Nodes.at(idxNode)->visited = true;

    Node<T> * node;
    while (!nodesQueue.empty()){

        node = nodesQueue.front();
        nodesQueue.pop();

        for (unsigned int idxEdge = 0; idxEdge < node->adj.size(); idxEdge++){

            if (!(node->adj.at(idxEdge).used) && node->adj.at(idxEdge).next->visited == false)
            {
                node->adj.at(idxEdge).next->visited = true;
                node->adj.at(idxEdge).next->parent = node;
                node->adj.at(idxEdge).next->parentEdge = &node->adj.at(idxEdge);

                nodesQueue.push(node->adj.at(idxEdge).next);
            }
        }
        order.push_back(node);
    }
    return order;
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

    MaxHeap<Node<T> *> pQueue;
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
Graph<T> Graph<T>::updateRGraph(Graph<T> &G) {


    Graph<T> Gr; //residual graph

    std::vector<Node<T> *> GNodes = G.getAllNodesPtr();

    for (unsigned int idx = 0; idx < G.size(); idx++)
    {
        Gr.addNode(GNodes.at(idx)->value);
        Gr.getAllNodesPtr().at(idx)->id = GNodes.at(idx)->id;
    }
    for (unsigned int idx = 0; idx < G.size(); idx++)
    {

        for (unsigned int edge = 0; edge < GNodes.at(idx)->adj.size(); edge++)
        {

            unsigned int flow = GNodes.at(idx)->adj.at(edge).flow;
            unsigned int cap = GNodes.at(idx)->adj.at(edge).weight;
            if (flow < cap){
                //residual
                Gr.getAllNodesPtr().at(idx)->adj.at(
                        (Gr.addEdge(
                                idx,
                                Gr.findNodeIndex( GNodes.at(idx)->adj.at(edge).next->id),
                                cap - flow))
                ).dir = std::pair<Edge<T> *, bool> (&GNodes.at(idx)->adj.at(edge), true);

                //Gr.getAllNodesPtr().at(idx)->adj.at(pos).dir.first  = G.allNodes.at(idx).adj.at(edge).dir.first;
                //Gr.getAllNodesPtr().at(idx)->adj.at(pos).dir.second = G.allNodes.at(idx).adj.at(edge).dir.second;
            }
            if (flow > 0){
                //residual
                Gr.getAllNodesPtr().at(Gr.findNodeIndex( GNodes.at(idx)->adj.at(edge).next->id))->adj.at(
                        (Gr.addEdge(
                                Gr.findNodeIndex( GNodes.at(idx)->adj.at(edge).next->id),
                                idx,
                                flow))
                ).dir = std::pair<Edge<T> *, bool> (&GNodes.at(idx)->adj.at(edge), false);

                //Gr.getAllNodesPtr().at(idx)->adj.at(pos).dir.first  =  G.allNodes.at(idx).adj.at(edge).dir.first;
                //Gr.getAllNodesPtr().at(idx)->adj.at(pos).dir.second = !G.allNodes.at(idx).adj.at(edge).dir.second;
            }
        }
    }
    return  Gr;
}



template<class T>
unsigned int Graph<T>::edmondsKarp(unsigned int idxStart, unsigned int idxEnd) {
    for (unsigned int idx = 0; idx < size(); idx++)
    {
        for (unsigned int edge = 0; edge < allNodes.at(idx).adj.size(); edge++)
        {
            allNodes.at(idx).adj.at(edge).flow = 0;
            allNodes.at(idx).capacity = 0;
        }
    }

    setAllNotUsed();

    Graph<T> Gr = updateRGraph(*this);
    while (true){
        //buscar um caminho de incremento
        BFS(Gr, idxStart);
        if (Gr.getAllNodesPtr().at(idxEnd)->parent == nullptr) break; //n existem mais caminhos


        //std::vector<Node<T> *> nodesGr = Gr.getAllNodesPtr();

        std::vector<Edge<T> *> pathEdges;

        unsigned int capPath = INT_MAX;
        Node<T> * n = Gr.getAllNodesPtr().at(idxEnd);
        while (n->parentEdge != nullptr)
        {
            pathEdges.push_back(n->parentEdge);
            capPath = std::min(n->parentEdge->weight, capPath);
            n = n->parentEdge->prev;
        }


        for (unsigned int idxEdge = 0; idxEdge < pathEdges.size(); idxEdge++)
        {

            /* atualizar flow */
            if(pathEdges.at(idxEdge)->dir.second)
                pathEdges.at(idxEdge)->dir.first->flow = pathEdges.at(idxEdge)->dir.first->flow + capPath;


            else if (!pathEdges.at(idxEdge)->dir.second)
                pathEdges.at(idxEdge)->dir.first->flow = pathEdges.at(idxEdge)->dir.first->flow - capPath;
            }
        Gr = updateRGraph(*this);

    }

    for (unsigned int idxNode = 0; idxNode < allNodes.size(); idxNode++) allNodes.at(idxNode).capacity = 0;
    for (unsigned int idxNode = 0; idxNode < allNodes.size(); idxNode++)
    {
        if (idxNode == idxStart) allNodes.at(idxNode).capacity = INT_MAX;

        for (unsigned int idxEdge = 0; idxEdge < allNodes.at(idxNode).adj.size(); idxEdge++ )
        {
            allNodes.at(idxNode).adj.at(idxEdge).next->capacity += allNodes.at(idxNode).adj.at(idxEdge).flow;
        }
    }

    return allNodes.at(idxEnd).capacity;
    //Graph::Graph<T>
}

template<class T>
void Graph<T>::setAllParentNull() {
    for (unsigned int idx = 0; idx < allNodes.size(); idx++)
    {
        allNodes.at(idx).parent = nullptr;
        allNodes.at(idx).parentEdge = nullptr;
    }
}

template<class T>
unsigned int Graph<T>::scenario2_1(unsigned int size, unsigned int start, unsigned int finish,
                         std::vector<std::pair<unsigned int, std::stack<Edge<T> *>>> &solution) {

    unsigned int maxFlow = edmondsKarp(start,finish);
    if (size > maxFlow){
        std::cout << "cant transport so many people to destiny";
        return size - maxFlow; //pessoas que não consegue transportar
    };
    setAllNotUsed();

    while (size>0){
        BFS(*this, start);
        Edge<T> * edge;


        unsigned int minFlow = INT_MAX;
        edge = allNodes.at(finish).parentEdge;


        while (edge != nullptr)  //find minFlow;
        {
            minFlow = std::min(edge->flow, minFlow);
            edge = edge->prev->parentEdge;
        }


        if (minFlow >= size) size = 0;
        else size -= minFlow;


        edge = allNodes.at(finish).parentEdge;
        std::stack<Edge<T> *> path;

        while (edge != nullptr)
        {
            path.push(edge);

            edge->flow -= minFlow;
            if (edge->flow <= 0) edge->used = true;
            edge = edge->prev->parentEdge;
        }

        maxFlow -= minFlow;
        solution.emplace_back(minFlow, path);

    }

    return maxFlow; //pessoas que ainda podia transportar
}

template<class T>
unsigned int Graph<T>::scenario2_4(unsigned int size, unsigned int start, unsigned int finish) {

    std::vector<std::pair<unsigned int, std::stack<Edge<T> *>>> solution = {};
    scenario2_1(size, start, finish, solution);

    setTimeTo0();

    std::vector<std::vector<Edge<T> *>> allPaths;

    for (unsigned int idx = 0; idx < solution.size(); idx++){
        std::vector<Edge<T> *> path;

        while (!solution.at(idx).second.empty()){
            solution.at(idx).second.top()->used = true;
            path.push_back( solution.at(idx).second.top() );
            solution.at(idx).second.pop();
        }
        allPaths.push_back(path);
    }


    return allNodes.at(finish).waiting;
}


/*
template <class T>
std::vector<Edge<T> *> Graph<T>::smallWayMaxCap(Graph<T> & G, unsigned int startIdx, unsigned int endIdx, unsigned int maxDist, unsigned int dist)
{
    if (startIdx == endIdx) return {};
}

template<class T>
Graph<T> Graph<T>::minimumChanges(unsigned int idxStart, unsigned int idxEnd) {

    unsigned int count = BFS(*this, idxStart).size();



    std::vector<Edge<T>*>


    unsigned int dist[allNodes.size()];
    for (unsigned int idx = 0; idx < allNodes.size(); idx++)
    {
        dist[idx] = INT_MAX;
    }

    std::queue<unsigned int> indexes;
    indexes.push(idxStart);

    dist[idxStart] = 0;
    allNodes.at(idxStart).visited = true;

    while (!indexes.empty())
    {
        unsigned int idx = indexes.front();
        indexes.pop();

        for (unsigned int i = 0; i < allNodes.at(idx).adj.size();i++)
        {
            if (allNodes.at(idx)->adj.at(i).next->visited == false)
            {
                allNodes.at(idx)->adj.at(i).next->visited = true;
                dist[findNodeIndex(allNodes.at(idx)->adj.at(i).next->id)] = dist[idx] +1;
            }
        }
    }
    return Graph<T>();
}
*/
