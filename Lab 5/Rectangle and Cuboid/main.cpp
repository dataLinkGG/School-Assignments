#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "assignment.hpp"
#include "more_functions.hpp"

using namespace std;

int main()
{
    Rec r1;
    Cub c1;

    /* // This part is not needed for the assigent ====
    Point origin; // (0,0,0)
    Point p1(1,0,0);
    Point p2(0,1,0);
    Point p3(0,0,1);

    Vector side1(origin,p1);
    Vector side2(origin,p2);
    Vector side3(origin,p3);

    float length1 = side1.length();
    float length2 = side2.length();
    float length3 = side3.length();

    r1.modify(length1,length2); // 1 by 1
    c1.modify(length1,length2,length3); // 1 by 1 by 1

    */ // =============================================

    // Defines which entity should be displayed:
    enum GeoEntity{rectange,cuboid};
    GeoEntity type_of_entity = cuboid; // I want to display the cuboid I created above

    char option; // user option

    bool quit = false;
    while (quit == false) {
        cout << "Menu" << endl;
        cout << "[1] New rectange" << endl;
        cout << "[2] New cuboid" << endl;
        cout << "[3] Display properties" << endl;
        cout << "[4] Exit" << endl;
        cout << ">> "; cin >> option;

        system("clear");
        switch(option) {
            case '1':
                type_of_entity = rectange;
                r1.edit();
                system("clear");
                break;
            case '2':
                type_of_entity = cuboid;
                c1.edit();
                system("clear");
                break;
            case '3':
                if (type_of_entity == rectange) {
                    cout << "Rectange" << endl;
                    cout << "Algebraic representation: " << r1 << endl;
                    cout << "Sides:" << endl;
                    r1.dsp_sides();
                    cout << "Area: " << r1.area() << endl;
                    cout << "Diagonal: " << r1.diag() << endl;
                } else if (type_of_entity == cuboid) {
                    cout << "Cuboid" << endl;
                    cout << "Algebraic representation: " << c1 << endl;
                    cout << "Sides:" << endl;
                    c1.dsp_sides();
                    cout << "Area: " << c1.area() << endl;
                    cout << "Diagonal: " << c1.diag() << endl;
                } else { // Actually not using, just in case:
                    cout << "Enter something first" << endl;
                }
                cout << "Press ENTER to go back." << endl;
                cin.ignore(); // ignores getchar otherwise
                getchar();
                system("clear");
                break;
            case '4':
                quit = true;
                break;
        }
        system("clear");
    }
    return 0;
}
