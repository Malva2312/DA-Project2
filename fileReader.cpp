#include "fileReader.h"
#include <iostream>


FileReader::FileReader(): graph(){

}


int FileReader::fileLines() {
    lines=0;
    string line;
    ifstream file;
    file.open("stops.csv");
    if (!file.is_open()){
        cout<<"File not Found"<<endl;
    }
    while(getline(file,line)){
        lines+=1;
    }
    return lines-1;
}



const Graph &FileReader::getGraph() const {
    return graph;
}