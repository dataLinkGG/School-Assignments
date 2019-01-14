#include <iostream>
#include <string>

#define MAX_NAME_LENGTH 10
#define MAX_ID_LENGTH 6
#define MAX_YEAR 5

using namespace std;

string make_a_name(string name) {
    name[0] = toupper(name[0]);
    for (int i = 1; i < (int) name.length(); i++) {
        name[i] = tolower(name[i]);
    }
    return name;
}

bool isanum(const std::string& str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) ++it;
    return !str.empty() && it == str.end();
}

class Student {
private:
    string first_name;
    string family_name;
    int year_of_study;
    int id;
public:
    Student() {
        first_name = "";
        family_name = "";
        year_of_study = 0;
        id = 0;
    }
    void modify_fist_name(string new_value) {
        first_name = make_a_name(new_value);
    }
    void modify_family_name(string new_value) {
        family_name = make_a_name(new_value);
    }
    void modify_year_of_study(string new_value) {
        year_of_study = atoi(new_value.c_str());
    }
    void modify_id(string new_value) {
        id = atoi((new_value.substr(0,MAX_ID_LENGTH)).c_str());
    }

    void display_info() {
        cout << endl << "Displaying infomation..." << endl;
        cout << endl << "First name: " << first_name << endl;
        cout << "Family name: " << family_name << endl;
        cout << "Year of study: " << year_of_study << endl;
        cout << "Student id: "; printf("%06d\n",id);
    }
};

int main()
{
    bool error = false;
    std::string user_input;
    Student login;
    do {
        try {
            cout << "first name: ";
            cin >> user_input;
            if (user_input.length() > MAX_NAME_LENGTH) {
                throw(user_input);
            } else {
                login.modify_fist_name(user_input);
            }
            cout << "family name: ";
            cin >> user_input;
            if (user_input.length() > MAX_NAME_LENGTH) {
                throw(user_input);
            } else {
                    login.modify_family_name(user_input);
            }
            cout << "year of studies: ";
            cin >> user_input;
            if (isanum(user_input)) {
                login.modify_year_of_study(user_input);
            } else {
                throw(user_input);
            }
            cout << "student id: ";
            cin >> user_input;
            if (isanum(user_input)) {
                login.modify_id(user_input);
            } else {
                throw(user_input);
            }
            error = false; // ok, we're good.
        } catch (string e) {
            cout << "Invalid input!" << endl;
            error = true; // reset the loop
        }
    } while (error);

    login.display_info();

    return 0;
}
