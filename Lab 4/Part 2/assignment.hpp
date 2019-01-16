#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

using namespace std;

class Color
{
private:
    int r,g,b;
public:
    Color();
    Color(const Color &);
    Color(int,int,int);
    void display();
    Color(const char*);
    string code();
    friend ostream& operator<<(ostream& os, const Color& c); // let's overload <<
};


class Vehicle
{
protected:
    typedef struct DIMENSIONS {
        float length; // 4.287 [m]
        float width; // 1.820 [m]
        float height; // 1.140 [m]
    } tDimensions;
    std::string model;
    std::string assembly;
    std::string vehicle_class;
    std::string manufacturer;
    int year;
    int seats;
    Color color;
    std::string engine;
    int gears;
    float top_speed;
    float curb_weight; // 1138.00 [Kg] ("kerb weight" in British English)
    tDimensions dim;
public:
    Vehicle();
    Vehicle(const char* file_path);
    void display();
    void save(const char* file_path);
    void reload(const char* _file_path);
    void edit();
    virtual std::string gen_plate() = 0; // Plates could be different depending on the vehicle.
};

class Car : public Vehicle
{
public:
    Car(); // basic initialization
    Car(string, Color);
    Car(const char*);
    string gen_plate();
};

class Bus : public Vehicle
{
public:
    Bus();
    Bus(string, int);
    Bus(const char*);
    string gen_plate();
};

string dec2hex_c(unsigned int);

string dec2hex(int);

void dsp_error_msg();

int hex2dec(string);

float kph_2_mph(float);

float mm_2_in(float);

float kg_2_lb(float);

#endif // ASSIGNMENT_CPP
