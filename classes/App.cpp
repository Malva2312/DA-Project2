#include "App.h"

using namespace std;


void App::print_allPaths(vector<pair<unsigned int, stack<Edge<int> *>>> allPaths, int & capacity){

    for (auto & allPath : allPaths)
    {
        cout << allPath.first << " people can go in this path :\t";
        capacity+=allPath.first;
        while (allPath.second.size()>1){

            cout << allPath.second.top()->prev->value << "\t->\t";
            allPath.second.pop();
        }
        cout << allPath.second.top()->prev->value << "\t->\t";
        cout << allPath.second.top()->next->value << endl;
    }

}

int App::run() {
    int option;
    int option2;
    int start;
    int finish;
    int size;
    cout <<endl<< "Welcome to our travel agency!" << endl;
    while (true) {
        string filename="../Tests/in";
        cout <<endl<< "Please choose what you would like to do"
             << endl << endl << "1. See a path that maximizes the number of people in a group" << endl
             << "2. See a path that maximizes the number of people in a group while minimizing the number of stops" << endl << "3. See a path given the dimension of the group (allows to increase group size if there is still space left)" << endl
             << "4. See the maximum possible size of a group as well as the best path for them"<<endl
             << "5. See when the group would reunite at the finish of the path (acyclic graph) as well as the maximum waiting time and where it happens"<<endl
             << "6. Exit"<<endl;
        cin >> option;
        if (cin.fail()) {
            throw invalid_argument("Please choose a valid number");
        }
        switch (option) {
            case 1:
                while (true){
                    cout<<endl<<"Enter the number of the dataset (1-10)"<<endl;
                    cin>>option2;
                    if (option2>10 || option2<1){
                        cout<<"Please write a number between 1-10"<<endl;
                        continue;
                    }
                    else{
                        if (option2>=10){
                            filename=filename+ to_string(option2)+".txt";
                        }
                        else{
                            filename=filename+ "0"+to_string(option2)+".txt";
                        }
                        FileReader file(filename);
                        Graph<int> test = Graph<int>();
                        file.initGraph(&test);
                        while (true){
                            cout<<endl<<"Enter the starting node"<<endl;
                            cin>>start;
                            if (start>test.getAllNodes().size() || start<1){
                                cout<<"Please write a number between 1-"<<test.getAllNodes().size()<<endl;
                                continue;
                            }
                            else{
                                int start2=test.findNodeIndex(start);
                                cout<<endl<<"Enter the last node"<<endl;
                                cin>>finish;
                                if (finish>test.getAllNodes().size() || finish<1){
                                    cout<<"Please write a number between 1-"<<test.getAllNodes().size()<<endl;
                                    continue;
                                }
                                else{
                                    int finish2=test.findNodeIndex(finish);
                                    test.maxCapacity(start2);
                                    Node<int>  * node = &test.getAllNodes().at(finish2);
                                    int maxCap = node->capacity;
                                    stack<int> path;
                                    while (node != nullptr)
                                    {
                                        path.push(node->value);
                                        node = node->parent;
                                    }
                                    cout<<"start: "<<path.top()<<"-->";
                                    path.pop();
                                    while(!path.empty()){
                                        cout<<path.top();
                                        path.pop();
                                        if (!path.empty()){
                                            cout<<"-->";
                                        }
                                        else{
                                            cout<<" finish";
                                        }
                                    }
                                    cout<<endl<<"Between these nodes this path has the maximum capacity of all the paths with a capacity of "<<maxCap<<" people"<<endl;

                                    break;
                                }

                            }
                        }
                        break;
                    }
                }
                continue;
            case 2:
                while (true){
                    cout<<endl<<"Enter the number of the dataset (1-10)"<<endl;
                    cin>>option2;
                    if (option2>10 || option2<1){
                        cout<<"Please write a number between 1-10"<<endl;
                        continue;
                    }
                    else{
                        if (option2>=10){
                            filename=filename+ to_string(option2)+".txt";
                        }
                        else{
                            filename=filename+ "0"+to_string(option2)+".txt";
                        }
                        FileReader file(filename);
                        Graph<int> test = Graph<int>();
                        Graph<int> test2 = Graph<int>();
                        file.initGraph(&test);
                        file.initGraph(&test2);
                        while (true){
                            cout<<endl<<"Enter the starting node"<<endl;
                            cin>>start;
                            if (start>test.getAllNodes().size() || start<1){
                                cout<<"Please write a number between 1-"<<test.getAllNodes().size()<<endl;
                                continue;
                            }
                            else{
                                int start2=test.findNodeIndex(start);
                                cout<<endl<<"Enter the last node"<<endl;
                                cin>>finish;
                                if (finish>test.getAllNodes().size() || finish<1){
                                    cout<<"Please write a number between 1-"<<test.getAllNodes().size()<<endl;
                                    continue;
                                }
                                else{
                                    int finish2=test.findNodeIndex(finish);
                                    test.scenario1_2(start2,finish2,test,test2);

                                    break;
                                }

                            }
                        }
                        break;
                    }
                }

                continue;

            case 3:
                while (true){
                    cout<<endl<<"Enter the number of the dataset (1-10)"<<endl;
                    cin>>option2;
                    if (option2>10 || option2<1){
                        cout<<"Please write a number between 1-10"<<endl;
                        continue;
                    }
                    else{
                        if (option2>=10){
                            filename=filename+ to_string(option2)+".txt";
                        }
                        else{
                            filename=filename+ "0"+to_string(option2)+".txt";
                        }
                        FileReader file(filename);
                        Graph<int> test = Graph<int>();
                        file.initGraph(&test);

                        while (true){
                            cout<<endl<<"Enter the size of the group"<<endl;
                            cin>>size;
                            vector<pair<unsigned int, stack<Edge<int> *>>> allPaths={};
                            int left = test.scenario2_1(size,0,test.getAllNodes().size()-1,allPaths);
                            if (left==INT_MAX){
                                cout<<endl<<"There is no path for that many people"<<endl;
                                continue;
                            }
                            int maxCap=left;
                            cout<<endl<<"space left: "<<left<<endl<<endl;
                            print_allPaths(allPaths,maxCap);
                            cout<<endl<<"max flow of the graph: "<<maxCap<<endl;
                            if (left>0){
                                cout<<endl<<"Since there is still space left, would you like to increase the size of your group? (our program will update the paths accordingly)"<<endl<<"If so press 1"<<endl;
                                cin>>option2;
                                if (cin.fail()){
                                    throw invalid_argument("Please input a valid number");

                                }
                                if (option2==1){
                                    allPaths.clear();
                                    continue;
                                }
                                else{
                                    break;
                                }
                            }
                            break;

                        }
                    }
                    break;
                }
                continue;

            case 4:
                while (true){
                    cout<<endl<<"Enter the number of the dataset (1-10)"<<endl;
                    cin>>option2;
                    if (option2>10 || option2<1){
                        cout<<"Please write a number between 1-10"<<endl;
                        continue;
                    }
                    else{
                        if (option2>=10){
                            filename=filename+ to_string(option2)+".txt";
                        }
                        else{
                            filename=filename+ "0"+to_string(option2)+".txt";
                        }
                        FileReader file(filename);
                        Graph<int> test = Graph<int>();
                        file.initGraph(&test);
                        vector<pair<unsigned int, stack<Edge<int> *>>> allPaths={};
                        int startPoint = 0;
                        int endPoint = test.size()-1;
                        int max = test.edmondsKarp(startPoint,endPoint);
                        test.scenario2_1(max,startPoint,endPoint,allPaths);
                        int maxCap=0;
                        print_allPaths(allPaths,maxCap);
                        cout<<endl<<"max flow of the graph: "<<maxCap<<endl;

                    }
                    break;
                }
                continue;
            case 5:
                while (true){
                    cout<<endl<<"Enter the number of the dataset (1-10)"<<endl;
                    cin>>option2;
                    if (option2>10 || option2<1){
                        cout<<"Please write a number between 1-10"<<endl;
                        continue;
                    }
                    else{
                        if (option2>=10){
                            filename=filename+ to_string(option2)+".txt";
                        }
                        else{
                            filename=filename+ "0"+to_string(option2)+".txt";
                        }
                        FileReader file(filename);
                        Graph<int> test = Graph<int>();
                        file.initGraph(&test);
                        while (true){
                            cout<<endl<<"Enter the size of the group"<<endl;
                            cin>>size;
                            cout<<endl<<"Enter the starting node"<<endl;
                            cin>>start;
                            cout<<endl<<"Enter the last node"<<endl;
                            cin>>finish;
                            if (finish>test.getAllNodes().size()){
                                cout<<endl<<"Finish node doesnt exist"<<endl;
                                continue;
                            }
                            else{
                                vector<pair<unsigned int, stack<Edge<int> *>>> allPaths={};
                                cout <<  test.scenario2_1(size, 0, test.getAllNodes().size()-1, allPaths) << " left" << endl;
                                int maxCap=0;
                                print_allPaths(allPaths,maxCap);
                                cout <<endl;
                                int start2=test.findNodeIndex(start);
                                int finish2=test.findNodeIndex(finish);
                                test.scenario2_4(size, start2, finish2, allPaths);
                                int maxWait;
                                int location;
                                for (Node<int> * node : test.getAllNodesPtr())
                                {
                                    if (node->visited){
                                        if (node->waiting_last-node->waiting_first>maxWait){
                                            maxWait=node->waiting_last-node->waiting_first;
                                            location=node->value;
                                        }
                                        cout << node->value << " :  first " << node->waiting_first << " -- " << " last " << node->waiting_last << endl;
                                    }
                                };
                                cout<<endl<<"The maximum wait time is "<<maxWait<<" on location "<<location<<endl;
                                break;
                            }

                        }

                    break;
                    }

                }

                continue;
            case 6:{

                return 0;
            }

            default:
                continue;
        }
    }
}
