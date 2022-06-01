#include "FileReader.h"


FileReader::FileReader(){
    string line;
    ifstream file;
    file.open("../Tests/in01.txt");
    if (!file.is_open()){
        cout<<"File not Found"<<endl;
    }
    getline(file,line,' ');
    this->nodesNumber=stoi(line);
}

void FileReader::initGraph(Graph<int> *graph) const {
    for (int i=1;i<nodesNumber+1;i++){
        graph->addNode(i);
    }
    int firstLineSkip=0;
    string line;
    ifstream file;
    file.open("../Tests/in01.txt");
    if (!file.is_open()){
        cout<<"File not Found"<<endl;
    }
    while(getline(file,line)){
        if (firstLineSkip==0){
            firstLineSkip=1;
            continue;
        }
        stringstream str(line);
        string word;
        vector<string> row;
        while(getline(str,word,' ')){
            row.push_back(word);
        }
        graph->addEdge(stoi(row[0]) - 1 ,stoi(row[1]) - 1 ,stoi(row[2]),stoi(row[3]));
    }

    /*
    for (int i=0;i<graph->getAllNodes().size();i++){
        cout<<graph->getAllNodes()[i].id<<endl;
    }
     */

}


