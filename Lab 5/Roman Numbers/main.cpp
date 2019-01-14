#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <cstdio>

using namespace std;

class ArabianNumbers {
protected:
    int value;
public:
    ArabianNumbers() {
        value = 0;
    }
    ArabianNumbers(int _m_value) {
        value = _m_value;
    }
    int dig_value(char r) {
        if (r == 'I') {
            return 1;
        } else if (r == 'V') {
            return 5;
        } else if (r == 'X') {
            return 10;
        } else if (r == 'L') {
            return 50;
        } else if (r == 'C') {
            return 100;
        } else if (r == 'D') {
            return 500;
        } else if (r == 'M') {
            return 1000;
        } else {
            return -1;
        }
    }
    int roman2decimal(string roman_num) {
        string str = roman_num;
        int res = 0;
        for (int i=0; i < (int) str.length(); i++) {
            int s1 = dig_value(str[i]);
            if (i+1 < (int) str.length()) {
                int s2 = dig_value(str[i+1]);
                if (s1 >= s2) {
                    res = res + s1;
                } else {
                    res = res + s2 - s1;
                    i++;
                }
            } else {
                res = res + s1;
                i++;
            }
        }
        return res;
    }
    string arab2roman(int a) {
        string ans;
        string M[] = {"","M","MM","MMM"};
        string C[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string I[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        ans = M[a/1000]+C[(a%1000)/100]+X[(a%100)/10]+I[(a%10)];
        return ans;
    }
    string arab2roman() {
        int a = value;
        string ans;
        string M[] = {"","M","MM","MMM"};
        string C[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string I[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        ans = M[a/1000]+C[(a%1000)/100]+X[(a%100)/10]+I[(a%10)];
        return ans;
    }
    void display() {
        cout << value << endl;
    }
    void modify(int num) {
        value = num;
    }
};

class Roman_Numbers : ArabianNumbers {
public:
    Roman_Numbers() : ArabianNumbers() {
    }
    Roman_Numbers(string _m_value) {
        value = roman2decimal(_m_value);
    }
    Roman_Numbers(int _m_value) : ArabianNumbers(_m_value) {
    }
    void display() {
        cout << arab2roman(value) << endl;
    }
    void modify(string num) {
        value = (int) roman2decimal(num);
    }
    int get_value() {
        return value;
    }
};

int main()
{
    ArabianNumbers arb;
    Roman_Numbers rom;

    enum NumberType {Arabian,Roman};
    NumberType out = Arabian;

    bool quit = false;
    char option;
    string user_input;

    while (quit == false) {
        system("clear");
        cout << "Menu" << endl;
        cout << "[1] Insert a Roman number" << endl;
        cout << "[2] Insert a Arabian number" << endl;
        cout << "[3] Dislay last entry" << endl;
        cout << "[4] Exit" << endl;
        cout << ">> ";
        getline(cin,user_input); option = (user_input.c_str())[0];
        switch(option) {
            case '1':
                system("clear");
                cout << ">> ";
                getline(cin,user_input);
                rom.modify(user_input.c_str());
                out = Roman;
                break;
            case '2':
                system("clear");
                cout << ">> ";
                getline(cin,user_input);
                arb.modify(atoi(user_input.c_str())); // cuz of atoi
                out = Arabian;
                break;
            case '3':
                system("clear");
                if (out == Arabian) {
                    cout << "ARABIAN" << endl;

                    cout << "Arabian format: ";
                    arb.display();
                    cout << "Roman format: ";
                    cout << arb.arab2roman() << endl;
                    //cin.ignore();
                    cout << "Press ENTER to continue." << endl;
                    getchar();
                } else if (out == Roman) {
                    cout << "ROMAN" << endl;
                    cout << "Roman number: ";
                    rom.display();
                    cout << "Arabian format: ";
                    cout << rom.get_value() << endl;
                    //cin.ignore();
                    cout << "Press ENTER to continue." << endl;
                    getchar();
                } else {
                    cout << "Please enter something first." << endl;
                }

                break;
            case '4':
                quit = true;
                break;
        }
    }

    return 0;
}
