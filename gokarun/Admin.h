#ifndef _ADMIN_H
#define _ADMIN_H
#include <string>
#include <vector>
#include "Car.h"

class Admin {
public: 
        
    string getAdminId();

    void addCar(vector<Car>& cars);

    void deleteCar(vector<Car>& cars);
    
    void editCarStatus(vector<Car>& cars);

    Admin(string id, string password);
    
private: 
    std::string AdminId;
    std::string Password;
};

#endif //_ADMIN_H