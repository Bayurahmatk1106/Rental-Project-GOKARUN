#include <iostream>
#include <string>
#include <vector>
#include "Car.h"

using namespace std;

//Setter untuk tipe mobil
void Car::setType(string tipe){
    Type = tipe;
}

//Setter harga mobil
void Car::setPrice(double price){
    Price = price;
}

//Setter status perentalan mobil
void Car::setStatus(string stat){
    Status = stat;
}

//Getter tipe mobil
string Car::getType(){
    return Type;
}

//Getter harga mobil
double Car::getPrice(){
    return Price;
}

//Getter status penyewaan mobil
string Car::getStatus(){
    return Status;
}

/*Getter yang mengubah data-data mobil yang berbeda tipe data menjadi string untuk
mengouput data mobil ke database mobil(car.txt)*/
string Car::getString(){
    return Type + " " + to_string(Price) + Status + '\n';
}

/*Method untuk mengoutput data-data sebuah mobil ke console*/
void Car::showCar(){
    cout << "------------------------------\n"; 
        cout << "   Type      :" << getType() << '\n'; 
        cout << "   Price/day :" << getPrice() << '\n';
        cout << "   Status    :" << getStatus() << '\n';
        cout << "------------------------------\n";
}


/*Method untuk mengoutput data semua mobil yang disimpan dalam vector*/
void Car::showAllCars(vector<Car> cars){
    int nomor = 1;
    for (Car car : cars) {
        cout << "------------------------------\n"; 
        cout << nomor << ". Type      :" << car.getType() << '\n'; 
        cout << "   Price/day :" << car.getPrice() << '\n';
        cout << "   Status    :" << car.getStatus() << '\n';
        cout << "------------------------------\n"; 
        nomor ++;
    }
}

//Constructor
Car::Car(string tip, double prc, string stat){
     Type = tip; Price = prc;Status = stat;
}