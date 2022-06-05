#include "App.h"


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
             << "2. See a path that maximizes the number of people in a group while minimizing the number of stops" << endl << "3. See a path given the dimension of the group" << endl
             << "4. See path from option 3 but improved to allow for a certain number of people to be added to the group" << endl << "5. See the maximum possible size of a group as well as the best path for them"<<endl
             << "6. See when the group would reunite at the finish of the path (acyclic graph) "<< endl << "7. See the maximum waiting time that one group would have to wait for the other if they started at the same time and place" <<endl
             << "8. Exit"<<endl;
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
                                    cout<<endl<<"Between those two nodes this path has the maximum capacity of all the paths with a capacity of "<<maxCap<<" people"<<endl;

                                    break;
                                }

                            }
                        }
                        break;
                    }
                }
                continue;
            case 2:


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

                            break;

                        }
                    }
                    break;
                }
                continue;

            case 4:

                continue;
            case 5:

                continue;
            case 6:

                continue;
            case 7:{

                continue;
            }
            case 8:{

                return 0;
            }
            default:
                continue;
        }
    }
}



#include "App.h"
