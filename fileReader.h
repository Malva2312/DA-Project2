//
// Created by andre on 27/05/22.
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

    const Graph &getGraph() const;

private:
    Graph graph;
    int lines;
};


#endif //DA_PROJECT2_FILEREADER_H
