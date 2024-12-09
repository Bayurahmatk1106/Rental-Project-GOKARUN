#ifndef _DATABASE_H
#define _DATABASE_H
#include <fstream>
#include <vector>
#include "Renter.h"
#include "Car.h"
using namespace std;

class Database {
    public:
    ifstream in;
    ofstream out;
    string fileName;

    Database(const char* filename);
    
    void saveRenter(string data);

    void saveCar(Car data);

    void scanCar(vector<Car>& cars);

    bool SignInCheck(string un, string pass);

    void updateCarStatus(vector<Car>& cars);

};



#endif //_DATABASE_H