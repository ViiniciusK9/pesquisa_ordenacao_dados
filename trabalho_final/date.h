#ifndef _DATE_H_
#define _DATE_H_
#include <iostream>
#include <string>

using namespace std;


class Date{
    private:
    int day;
    int month;
    int year;

    public:
    Date();
    Date(int d, int m, int y);
    int getDay();
    int getMonth();
    int getYear();
    string toString();
};
#endif