
#ifndef DA_PROJECT2_FILEREADER_H
#define DA_PROJECT2_FILEREADER_H

#include <fstream>
#include "Graph.h"

using namespace std;

class FileReader {

public:
    FileReader();
    void initGraph(Graph<int> * graph) const;

private:
    int nodesNumber;
};



#endif //DA_PROJECT2_FILEREADER_H

