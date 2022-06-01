#include "app.h"


int app::run() {
    int option;
    cout <<endl<< "Welcome to our travel agency!" << endl;
    while (true) {

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

                continue;
            case 2:
            {

                continue;
            }
            case 3:
            {

                continue;
            }
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



#include "app.h"
