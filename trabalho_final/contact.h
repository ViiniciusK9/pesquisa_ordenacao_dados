#ifndef _CONTACT_H_
#define _CONTACT_H_
#include <iostream>
#include "date.h"

using namespace std;


class Contact{
    private:
    string name;
    Date birth;
    string email;
    string phone;

    public:
    Contact();
    Contact(string n, Date b, string e, string p);
    string getNome();
    string getEmail();
    string getPhone();
    string getDate();
};
#endif