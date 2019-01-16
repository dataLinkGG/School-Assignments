#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include "assignment.hpp"

using namespace std;

int main()
{
    char option; // 1, 2, 3, or 4.
    bool quit = false; // quits the program
    string user_input; // will be converted if necessary
    Car v1; // it could be a Bus as well, but not a Vehicle
    while (quit == false) {
        system("clear");
        cout << "Menu" << endl;
        cout << "[1] Insert a new vehicle" << endl;
        cout << "[2] Load a vehicle from a file" << endl;
        cout << "[3] Dislay and Save" << endl;
        cout << "[4] Exit" << endl;
        cout << ">> ";
        getline(cin,user_input); option = (user_input.c_str())[0];
        switch(option) {
            case '1':
                system("clear");
                v1.edit();
                break;
            case '2':
                system("clear");
                cout << "Enter path: ";
                getline(cin,user_input);
                v1.reload(user_input.c_str());
                break;
            case '3':
                system("clear");
                v1.display();
                cout << "Save on a file? [y/n]" << endl;
                cout << ">> ";
                getline(cin,user_input); option = (user_input.c_str())[0];
                if (option == 'y') {
                    system("clear");
                    cout << "Enter path: ";
                    getline(cin,user_input); v1.save(user_input.c_str());
                }
                break;
            case '4':
                quit = true;
                break;
        }
    }

    return 0;
}
