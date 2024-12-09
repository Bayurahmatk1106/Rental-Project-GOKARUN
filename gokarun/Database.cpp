#include "Database.h"
#include "Renter.h"
#include "Car.h"
#include <iostream>
#include <fstream>
#include <vector>

/*Constructor*/
Database::Database(const char* filename){
    fileName = filename;
}

/*Method untuk menyimpan data pengguna baru*/
void Database::saveRenter(string data){
    //Membuka file text, append untuk menambah data tanpa menghapus isi file yang sudah ada
    out.open(fileName,ios::app);

    //Mengouput data pengguna baru yang sudah dijadikan string menuju database renter.txt
    out << data;

    //Menutup file
    out.close();
}

/*Method untuk menyimpan data mobil baru ke database*/
void Database::saveCar(Car data){

     //Membuka file text, append untuk menambah data tanpa menghapus isi file yang sudah ada
    out.open(fileName,ios::app);

     //Mengouput data mobil baru yang sudah dijadikan string menuju database car.txt
    out << data.getString();

    //Menutup file
    out.close();
}

/*Method yang mengisi vector berisi data mobil-mobil yang diinisialisasi pada saat awal program berjalan*/
void Database::scanCar(vector<Car>& cars){
    string tipe, status;double harga;

    //Membuka file
    in.open(fileName,ios::in);

    //Iterasi untuk menginisialisasi vector data mobil-mobil
    while (in >> tipe >> harga >> status){
        Car car(tipe, harga, status);
        cars.push_back(car);
    }

    //Menutup file
    in.close();
}

/*Mengecek kecocokan username dan password di database dengan 
username dan password yang diinputkan user*/
bool Database::SignInCheck(string un, string pass){
    string username, password;

    //Membuka file
    in.open(fileName);

    //Mengecek username dan password dari user
    while(getline(in, username)) {
        getline(in, password);

        //Jika username dan password benar:
        if (username == un && pass == password) {
            in.close();
            return true;
        }
    }

    //Menutup file:
    in.close();

    //Jika username atau password salah atau akun tidak ada
    return false;
}

/*Method untuk memperbarui database mobil dari perubahan vektor mobil*/
void Database::updateCarStatus(vector<Car>& cars){ 
    //Membuka mobil  
    out.open(fileName, ios::out);

    //Memperbarui file dengan ios::out hanya untuk baris pertama
    out << cars[0].getType() << " " << cars[0].getPrice() << " " << cars[0].getStatus() <<'\n';
    out.close();

    //Memasukkan sisa anggota vektor mobil 
    for (int i =1; i < cars.size(); i ++){
        out.open(fileName, ios::app);
        out << cars[i].getType() << " " << cars[i].getPrice() << " " << cars[i].getStatus() <<'\n';
        out.close();
    }
}
