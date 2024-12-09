#include "Admin.h"
#include "Car.h"
#include "Database.h"
#include <iostream>
#include <vector>


//Method untuk memanggil Id Admin yang bersifat private
string Admin::getAdminId() {
    return AdminId;
}


//Method untuk menambah mobil untuk disewakan
void Admin::addCar(vector<Car>& cars){
    string tipe, status;
    double price;
    cout << "Car Type        : "; cin >> tipe;
    cout << "Car's Price/day : "; cin >> price;
    status = "Available";
    Car newCar(tipe, price, status);
    cars.push_back(newCar);
}

/*Method untuk menghapus mobil dengan memajukan vektor Car berindeks i+1  
 ke index i dan menghapus index vektor paling belakang */
void Admin::deleteCar(vector<Car>& cars){
    int car_index;
    cout << "Number of car : ";cin >> car_index;
    int vector_car_index = car_index - 1;
    for (int j = vector_car_index; j < cars.size() - 1; j++){
        cars[j] = cars[j+1];
    }
    cars.pop_back();
}

/*Method untuk mengubah status mobil yang terental menjadi tersedia kembali
saat mobil sudah dikembalikan*/    
void Admin::editCarStatus(vector<Car>& cars){
    int rented_car_index;
    cout << "Number of car : ";cin >> rented_car_index;
    cars[rented_car_index-1].setStatus("Available");
}

/*Constructor*/
Admin::Admin(string id, string password){
    AdminId = id;
    Password = password;
}