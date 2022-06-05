//
// Created by andre on 01/06/22.
//

#ifndef DA_PROJECT2_APP_H
#define DA_PROJECT2_APP_H
#include "FileReader.h"
#include <iostream>
#include <stack>


class App {
public:
    int run();
    void print_allPaths(vector<pair<unsigned int, stack<Edge<int> *>>> allPaths, int & capacity);

private:

};


#endif //DA_PROJECT2_APP_H
