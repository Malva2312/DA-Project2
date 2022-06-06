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
    /**
     * Runs the user interface allowing the user to input values and to see all the scenarios in action
     * @return returns 0 upon conclusion
     */
    int run();

    /**
     * Aux funciton that prints every path given a vector (used in scenarios 2.1-2.5)
     * @param allPaths
     * @param capacity
     */
    void print_allPaths(vector<pair<unsigned int, stack<Edge<int> *>>> allPaths, int & capacity);

private:

};


#endif //DA_PROJECT2_APP_H
