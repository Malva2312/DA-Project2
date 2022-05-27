//
// Created by Utilizador on 27/05/2022.
//

#ifndef DA_PROJECT2_FILEREADER_H
#define DA_PROJECT2_FILEREADER_H



#include <fstream>
#include "Graph.h"

using namespace std;

class FileReader {

public:
    FileReader();
    int fileLines();
    void readEdges();

    const Graph<int> &getGraph() const;

private:
    Graph<int> graph;
    int lines;
};



#endif //DA_PROJECT2_FILEREADER_H
