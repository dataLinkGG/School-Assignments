#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include "assignment.hpp"

using namespace std;

Vehicle::Vehicle()
{
    Color std_color("white");
    model = "?";
    color = std_color;
    vehicle_class = "?";
    year = 0;
    manufacturer = "?";
    assembly = "?";
    seats = 0;

    engine = "?";
    gears = 0;
    top_speed= 0;

    dim.length = 0;
    dim.width = 0;
    dim.height = 0;
    curb_weight = 0;
}

Vehicle::Vehicle(const char* file_path) : Vehicle() // I'm delegating constructor bcz floats atributes are getting weird values
{
    ifstream file;
    string color_code;
    file.open(file_path);
    if(!file) {
        dsp_error_msg();
        return;
    }
    getline(file,model);
    getline(file,color_code); Color new_color(color_code.c_str()); color = new_color;
    getline(file,vehicle_class);
    file >> year; file.ignore(); // ignores \n that file >> str has lefted
    getline(file,manufacturer);
    getline(file,assembly);
    file >> seats; file.ignore();
    getline(file,engine);
    file >> gears;
    file >> top_speed;
    file >> dim.length;
    file >> dim.width;
    file >> dim.height;
    file >> curb_weight;

    file.close();
}

void Vehicle::display()
{
    cout << "Model: " << model << endl;
    cout << "Color: " << color << endl;
    cout << "Class: " << vehicle_class << endl;
    cout << "Year: " << year << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Assembly in: " << assembly << endl;
    cout << "Number of seats: " << seats << endl;

    cout << "Engine: " << engine << endl;
    cout << "Number of gears: " << gears << endl;
    cout << "Top speed: " << top_speed<< " km/h " << "(" << kph_2_mph(top_speed) << " mph)" << endl;

    cout << "Length: " << dim.length << " mm" << " (" << (trunc(10*mm_2_in(dim.length)))/10 << " in)"<< endl; // to be continued <<
    cout << "Width: " << dim.width << " mm" << " (" <<  round(mm_2_in(dim.width)) << " in)" << endl;
    cout << "Height: " << dim.height << " mm" << " (" <<  round(mm_2_in(dim.length)) << " in)" << endl;
    cout << "Curb weight : " << curb_weight << " kg" << " (" << kg_2_lb(curb_weight) <<  " lb)" << endl;

    cout << endl;
}


void Vehicle::save(const char* file_path) // save a vehicle to a file
{
    ofstream file;
    file.open(file_path);
    if(!file) {
        dsp_error_msg();
        return;
    }
    file << model << endl;
    file << color.code().c_str() << endl;
    file << vehicle_class << endl;
    file << year << endl;
    file << manufacturer << endl;
    file << assembly << endl;
    file << seats << endl;

    file << engine << endl;
    file << gears << endl;
    file << top_speed<< endl;

    file << dim.length << endl;
    file << dim.width << endl;
    file << dim.height << endl;
    file << curb_weight << endl;

    file.close();
}

void Vehicle::reload(const char* _file_path) // edit using data from a file
{
    ifstream file;
    std::string input;
    std::string color_code;
    file.open(_file_path);
    if(!file) {
        dsp_error_msg();
        return;
    }
    getline(file,model);
    getline(file,color_code); Color new_color(color_code.c_str()); color = new_color;
    getline(file,vehicle_class);
    getline(file,input); year = atoi(input.c_str()); // cin <<
    getline(file,manufacturer);
    getline(file,assembly);
    getline(file,input); seats = atoi(input.c_str());

    getline(file,engine);
    getline(file,input); gears = atoi(input.c_str());
    getline(file,input); top_speed= atof(input.c_str());

    getline(file,input); dim.length = atof(input.c_str());
    getline(file,input); dim.width = atof(input.c_str());
    getline(file,input); dim.height = atof(input.c_str());
    getline(file,input); curb_weight = atof(input.c_str());

    file.close();
}
    //file.close();



void Vehicle::edit() // modify attributes after instantiation
{
    std::string input; // << doesn't work properly with different types, the interface bugs out
    stringstream my_stream;
    cout << "Model: "; getline(cin,model); // cin >> model;
    cout << "Color: "; getline(cin,input); Color new_color(input.c_str()); color = new_color;
    cout << "Type: "; getline(cin,vehicle_class);
    cout << "Year: "; getline(cin,input); year = atoi(input.c_str());
    cout << "Manufacturer: "; getline(cin,manufacturer);
    cout << "Assembly: "; getline(cin,assembly);
    cout << "Seats: "; getline(cin,input); seats = atoi(input.c_str()); // <<
    cout << "Engine: "; getline(cin,engine);
    cout << "Gears: "; getline(cin,input); gears = atoi(input.c_str());
    cout << "Top speed: "; getline(cin,input); top_speed = atof(input.c_str());
    cout << "Length: "; getline(cin,input); dim.length = atof(input.c_str());
    cout << "Width: "; getline(cin,input); dim.width = atof(input.c_str());
    cout << "Height: "; getline(cin,input); dim.height = atof(input.c_str());
    cout << "Curb weight: "; getline(cin,input); curb_weight = atof(input.c_str());
}

Car::Car() : Vehicle() {}

Car::Car(string _model, Color _color) : Vehicle() // simple initialization
{
    model = _model;
    color = _color;
}

Car::Car(const char* _file_path) : Vehicle(_file_path) {}

string Car::gen_plate()
{
    string plate = "CONTRY\nAAA0000";
    return plate;
}

Bus::Bus() : Vehicle() {}

Bus::Bus(string _model, int _seats) : Vehicle() // simple initialization
{
    model = _model;
    seats = _seats;
}

Bus::Bus(const char* _file_path) : Vehicle(_file_path) {} // complete initialization

string Bus::gen_plate()
{
    string plate = "CONTRY\nBBB0000";
    return plate;
}

Color::Color()
{
    r = g = b = 0;
}

Color::Color(const Color &color2) // copy constructor
{
    r = color2.r;
    g = color2.g;
    b = color2.b;
}

Color::Color(int _red,int _green,int _blue)
{
    const unsigned MAX = 257; // higher than 256 is not allowed
    r = abs(_red) % MAX; // the range is supposed to be from 0 to 256
    g = abs(_green) % MAX;
    b = abs(_blue) % MAX;
}

Color::Color(const char* _code) // initialize obj using RGB hex _code "#000000"
{
    string str;

    if(!strcmp(_code,"white")) {
        r = 255; g = 255; b = 255;
    } else if (!strcmp(_code,"red")) {
        r = 255; g = 0; b = 0;
    } else if (!strcmp(_code,"lime")) {
        r = 0; g = 255; b = 0;
    } else if (!strcmp(_code,"blue")) {
        r = 0; g = 0; b = 255;
    } else if (!strcmp(_code,"yellow")) {
        r = 255; g = 255; b = 0;
    } else if (!strcmp(_code,"aqua")) {
        r = 0; g = 255; b = 255;
    } else if (!strcmp(_code,"magenta")) {
        r = 255; g = 0; b = 255;
    } else if (!strcmp(_code,"silver")) {
        r = 192; g = 192; b = 192;
    } else if (!strcmp(_code,"gray")) {
        r = 128; g = 128; b = 128;
    } else if (!strcmp(_code,"maroon")) {
        r = 128; g = 0; b = 0;
    } else if (!strcmp(_code,"olive")) {
        r = 128; g = 128; b = 0;
    } else if (!strcmp(_code,"green")) {
        r = 0; g = 128; b = 0;
    } else if (!strcmp(_code,"purple")) {
        r = 128; g = 0; b = 128;
    } else if (!strcmp(_code,"teal")) {
        r = 0; g = 128; b = 128;
    } else if (!strcmp(_code,"navy")) {
        r = 0; g = 0; b = 128;
    } else if (!strcasecmp(_code,"black")){
        r = 0; g = 0; b = 0;
    } else {
        str = "";
        str += _code[1];
        str += _code[2];
        r = hex2dec(str.c_str());

        str = "";
        str += _code[3];
        str += _code[4];
        g = hex2dec(str.c_str());

        str = "";
        str += _code[5];
        str += _code[6];
        b = hex2dec(str.c_str());
    }
}

string Color::code()
{
    string code = "#";
    code += dec2hex_c(r);
    code += dec2hex_c(g);
    code += dec2hex_c(b);
    return code;
}

void Color::display() // RGB format e.g.: rgb(255,0,0)
{
    cout << "rgb(" << r << "," << g << "," << b << ")" << endl; // format 1
}

ostream& operator<<(ostream& os, const Color& c)
{
    printf("#%02X%02X%02X",c.r,c.g,c.b); // format: #FF0000
    return os;
}

string dec2hex_c(unsigned int i) // has limit of 32 bit integer
{
    char s[20];
    sprintf(s, "%02X", i); //uppercase
    //sprintf(s, "%x", i); //lowercase
    return string(s);
}

string dec2hex(int i)
{
    stringstream ss;
    ss << hex << uppercase << i;
    //ss << hex << lowercase << i;
    //ss << showbase << hex << lowercase << i; //prepends 0x
    //string s; ss >> s; return s; //alternate way to extract string
    //cout << ss.str();
    return ss.str();
}

void dsp_error_msg()
{
    cout << "Error opening file!" << endl;
    cout << "Press ENTER to continue" << endl;
    getchar();
}

int hex2dec(string hex) // using ASCII table
{
    int dec = 0;
    int hex_base = 16;
    int dec_base = 10;
    for (int i=0; i< (int) hex.length(); i++) {
        if (hex[i]>='0' && hex[i]<='9') {
            dec += (hex[i]-'0')*pow(hex_base,hex.length()-i-1);
        } else if (hex[i]>='A' && hex[i]<='F') {
            dec += (hex[i]-('A'-dec_base))*pow(hex_base,hex.length( )-i-1);
        } else if (hex[i]>='a' && hex[i]<='f') {
            dec += (hex[i]-('a'-dec_base))*pow(hex_base,hex.length()-i-1);
        }
    }
    return dec;
}

float kph_2_mph(float speed_kph)
{
    return speed_kph / 1.609;
}

float mm_2_in(float length_mm)
{
    return length_mm / 25.4;
}

float kg_2_lb(float mass_kg)
{
    return mass_kg * 2.205;
}
