#ifndef _CAR_H
#define _CAR_H
#include <string>
using namespace std;

class Car {
public:
    void setType(string tipe);

    void setPrice(double price);

    void setStatus (string stat);

    string getType();

    double getPrice();

    string getStatus();

    string getString();

    void showCar();

    void showAllCars(vector<Car> cars);

    Car(std::string ty, double prc, string stat);

private: 
    string Type;
    double Price;
    string Status;
};

#endif //_CAR_H