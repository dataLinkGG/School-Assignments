#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

enum Months {jan,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};

class LongTime // Number of years, months and days
{
private:
    int d,m,y;
public:
    LongTime(int _d) {
        y = _d / 365;
        d = _d % 365;
        m = (_d % 365) / 30;
    }
    void display() {
        printf("%d years %d months %d days\n",y,m,d);
    }
};

class Date
{
private:
    int d,m,y;
public:
    Date() {
        d = 1;
        m = 1;
        y = 1;
    }
    Date(int _d,int _m,int _y) {
        d = _d;
        m = _m;
        y = _y;
    }
    int rdn() {
        int year = this->y;
        int month = this->m;
        int day = this->d;
        if (month < 3)
            year--, month += 12;
        return 365*year + year/4 - year/100 + year/400 + (153*month - 457)/5 + day - 306;
    }
    bool is_leap_year() {
        int year = this->y;
        bool is_leap;
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    is_leap = true;
                } else {
                    is_leap = false;
                }
            } else {
                is_leap = true;
            }
        } else {
            is_leap = false;
        }
        return is_leap;
    }
    int number_of_days(int _m) {
        return monthDays[_m];
    }
    int get_year() {
        return y;
    }
    int get_month() {
        return m;
    }
    int get_day() {
        return d;
    }
    void display() {
        printf("%02d/%02d/%d",d,m,y);
    }
    void display_month_name() {
        string name[] = {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
        cout << name[m];
    }
};

int main()
{
    Date dt2(1,10,2018);
    Date dt1(1,1,1997);

    int days = dt2.rdn() - dt1.rdn();

    LongTime t1(days);

    cout << "1) Number of days between the 2 dates: ";
    cout << days << endl;

    cout << "2) Number of years, months and days: ";
    t1.display();

    cout << "3) Number of days in ";
    dt1.display_month_name();
    cout << ": ";
    cout << dt1.number_of_days(jan) << endl;

    cout << "4) Is " << dt1.get_year() << " a leap year? ";
    if (dt2.is_leap_year())
        cout << "yes";
    else
        cout << "no";

    cout << endl;

    return 0;
}
