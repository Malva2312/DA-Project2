
#ifndef DA_PROJECT2_FILEREADER_H
#define DA_PROJECT2_FILEREADER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "Graph.cpp"
using namespace std;

class FileReader {

public:
    FileReader(string filename);
    void initGraph(Graph<int> * graph) const;

private:
    int nodesNumber;
    string const fileName;
};



#endif //DA_PROJECT2_FILEREADER_H

