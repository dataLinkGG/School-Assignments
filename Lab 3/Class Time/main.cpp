// overload_date.cpp
// compile with: /EHsc
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class Time
{
private:
    int hours,minutes,seconds;
public:
    Time() {
        seconds = 0;
        minutes = 0;
        hours = 0;
    }
    Time(int _seconds) {
        seconds = _seconds%60;
        minutes = (_seconds/60)%60;
        hours = (_seconds/60)/60;
    }
    Time(int _hours, int _minutes, int _seconds) {
        seconds = _seconds%60;
        minutes = (_minutes+_seconds/60)%60;
        hours = _hours+(_minutes+_seconds/60)/60;
    }
    Time operator+(const Time& t2) {
        Time t(this->hours + t2.hours,this->minutes + t2.minutes,this->seconds + t2.seconds);
        return t;
    }
    Time operator-(const Time& t2) {
        Time t((this->hours*60*60 + this->minutes*60 + this->seconds)-(t2.hours*60*60 + t2.minutes*60 + t2.seconds));
        return t;
    }
    friend ostream& operator<<(ostream& os, const Time& dt);
};

ostream& operator<<(ostream& os, const Time& dt)
{
    if (dt.seconds < 0 || dt.minutes < 0 || dt.hours < 0) {
        cout << "-";
    }
    printf("%02d:",abs(dt.hours));
    printf("%02d:",abs(dt.minutes));
    printf("%02d",abs(dt.seconds));
    return os;
}

int main()
{
    Time t1(5,6,1);
    Time t2(50,32,100);
    Time t3;
    t3 = t1 - t2;
    cout << t3;
}
