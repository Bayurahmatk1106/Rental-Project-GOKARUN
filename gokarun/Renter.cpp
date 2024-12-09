/**
 * Project Untitled
 */
#include <iostream>
#include <string>
#include <vector>
#include "Renter.h"
#include "Payment.h"
#include "Database.h"

using namespace std;

string Renter::getUsername() {
    return Username;
}

string Renter::getString(){
    return Username + "\n" + Password + "\n";
}

Renter::Renter(string n, string pass){
    Username = n;
    Password = pass;
}
    