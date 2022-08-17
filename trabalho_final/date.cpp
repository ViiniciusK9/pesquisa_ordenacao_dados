#include "date.h"
#include <string>

using namespace std;


    Date::Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }

    Date::Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    int Date::getDay()
    {
        return day;
    }

    int Date::getMonth()
    {
        return month;
    }

    int Date::getYear()
    {
        return year;
    }

    string Date::toString()
    {
        char a[166];
        sprintf(a, "%d,%d,%d", day, month, year);
        return  (string)a;
    }