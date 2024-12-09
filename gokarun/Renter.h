#ifndef _RENTER_H
#define _RENTER_H
#include <string>
#include "Database.h"
#include "Payment.h"
using namespace std;

class Renter {
public: 
    string getUsername();
    string getString();
    Renter(string n, string pass);

private: 
    string Username;
    string Password;
};

#endif //_RENTER_H