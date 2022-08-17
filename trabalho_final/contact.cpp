#include "contact.h"
#include "date.h"

using namespace std;

    Contact::Contact()
    { 
        name = " ";
    }

    Contact::Contact(string n, Date b, string e, string p)
    {
        name = n;
        birth = b;
        email = e;
        phone = p;
    }
    
    string Contact::getNome()
    {
        return name;
    }

    string Contact::getEmail()
    {
        return email;
    }

    string Contact::getPhone()
    {
        return phone;
    }

    string Contact::getDate()
    {
        return birth.toString();
    }