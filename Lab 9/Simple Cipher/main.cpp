#include <iostream>

#define ALPHABET_LENGTH 26

using namespace std;

void txt_cipher(string,int);
void txt_decipher(string,int);
void my_pause();
bool is_a_num(const std::string&);
bool parse_option(int);

int main(int argc,char* argv[])
{
    int key;
    string user_input;

    if (argc == 2) {
        parse_option(atoi(argv[1]));
    } else {
        do {
            system("clear");
            cout << "Enter the cipher key [0 to exit]: ";
            getline(cin,user_input); key = atoi(user_input.c_str());
        } while (parse_option(key) == false);
    }

    return 0;
}

void txt_cipher(string buffer, int key)
{
    key %= ALPHABET_LENGTH;
	  for(int i=0; i < (int) buffer.length(); i++) {
        if (buffer[i] == ' ') {
            putchar(buffer[i]);
        } else if (isalpha(buffer[i])) {
            for(int j=0; j<=key; j++) {
                buffer[i]++;
                if(buffer[i] > 'z') {
                    buffer[i] = 'a';
                }
                j++;
            }
            putchar(buffer[i]);
        } else {
            cout << "?";
        }
    }
	  cout << endl;
}

void txt_decipher(string buffer, int key)
{
    key = abs(key);
    key %= ALPHABET_LENGTH;
    for(int i=0; i < (int) buffer.length(); i++) {
          if (buffer[i] == ' ') {
              putchar(buffer[i]);
          } else if (isalpha(buffer[i])) {
              for(int j=0; j<=key; j++) {
                  buffer[i]--;
                  if(buffer[i] < 'a') {
                      buffer[i] = 'z';
                  }
                  j++;
              }
              putchar(buffer[i]);
          } else {
              cout << "?";
          }
    }
	  cout << endl;
}

bool parse_option(int key) {
    string user_input;
    bool exit;
    system("clear");
    if (key == 0) {
        cout << "Exiting..." << endl;
        exit = true;
    } else {
        cout << "PLAIN TEXT: " << endl << endl;
        getline(cin,user_input);
        if (key > 0) {
            cout << endl << "CIPHERED TEXT:" << endl << endl;
            txt_cipher(user_input.c_str(),key);
            my_pause();
        } else { // key < 0
            cout << endl << "CIPHERED TEXT:" << endl << endl;
            txt_decipher(user_input.c_str(),key);
            my_pause();
        }
        exit = false;
    }
    return exit;
}

bool is_a_num(const std::string& str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) ++it;
    return !str.empty() && it == str.end();
}

void my_pause() {
    cout << endl << "PRESS ENTER TO CONTINUE" << endl;
    getchar();
}

