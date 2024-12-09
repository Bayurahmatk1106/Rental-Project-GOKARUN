#include <bits/stdc++.h>
#include <fstream>
#include "Renter.h"
#include "Database.h"
#include "Car.h"
#include "Payment.h"
#include "Admin.h"

using namespace std;

void menuPage();
void returnToMenuPage();
void registPage();
void mainMenu();
void loginPage();
void carsMenu();
void PaymentPage();
void AdminPage();
void AddCarPage();
void DeleteCarPage();
void ReturnCarPage();

Database renter_database("renter.txt");
Database car_database("car.txt");
Database admin_database("admin.txt");
vector<Car> Cars; 
Car car1("car", 0, "available");
int rent_car_index;
char login_choice;
Admin admin = Admin("Admin", "-");
Renter renter = Renter("user", "-");

//inisialisasi state awal
char state = '1';

//nilai login awal
bool Login = false;

int main(){
    int rented_car_index;
    car_database.scanCar(Cars);
    while(true) {
        switch(state){
            case '1':
                mainMenu();
                break ;
            case '2':
                loginPage();
                break ;
            case '3':
                returnToMenuPage();
                break;
            case '4':
                break;
            case '5':
                menuPage();
                break;
            case '6':
                registPage();
                break;
            case '7':
                carsMenu();
                break;
            case '8':
                PaymentPage();
                break;
            case '9':
                AdminPage();
                break;   
            case 'a':
                AddCarPage();
                break;
            case 'b':
                DeleteCarPage();
                break;
            case 'c':
                ReturnCarPage();
                break;
        }
        if (state == '4'){
           cout << "\nExiting program...";
            break;
        }
    }    
    return 0;
}

void mainMenu(){
    cout << "\n=========================================================\n";
    cout << " #####   *****  #   #   ******  #####   ##  ##  #   #   \n";
    cout << "#       *     * #  #    *    *  #    #  ##  ##  ##  #   \n";
    cout << "#  ###  *     * ###     ******  #####   ##  ##  # # #   \n";
    cout << "#    #  *     * #  #    *    *  #   #   ##  ##  #  ##   \n";
    cout << " #####   *****  #   #   *    *  #    #   ####   #   #   \n";
    cout << "=========================================================\n\n";
    cout << "\nActivity : \n";
    cout << "1. See available cars\n";
    cout << "2. Sign Up\n";
    cout << "3. Sign in\n";
    cout << "4. Exit\nYour Choice : ";
    char input;
    cin >> input;
    if (input == '3') {
        state = '2';
        return ;
    } else if(input == '2'){
        state = '6';
        return;
    } else if (input == '4'){
        state = '4';
        return;
    } else if (input == '1'){
        state = '7';
        return;
    }
}

void menuPage(){
    cout << "=========RENTER'S MENU=========\n";
    cout << "1. View cars\n";
    cout << "2. Sign out\n";
    cout << "3. Exit\n";
    cout << "Your choice : ";
    char input;
    cin >> input;
    if (input == '1'){
           state = '7';
           return ;
        } else if (input == '2'){
           Login = false;
           renter = Renter("user", "-");
           state = '1';
           return ; 
        } else if (input == '3'){
            state = '4';
            return;
        }
}

void carsMenu(){
    char choice, choice2, choice3;
    car1.showAllCars(Cars);
    cout << "1.Rent\t\t2.Back\nYour Choice :";cin >> choice;
    if (choice == '1'){
        if(Login == true){
            int i;
            cout <<  "\nInsert the Car's number: ";cin >>i;
            car1 = Cars[i-1];
            while (car1.getStatus() == "Rented"){
                cout << "The car has been rented, please choose other available car\n";
                car1.showAllCars(Cars);
                cout << "Your choice: " ;cin >> i;
                car1 = Cars[i-1];
            }
            car1.showCar();
            cout << "1.Continue to payment\t2.Back\nYour choice: ";cin >> choice3;
            if (choice3 == '1'){
                rent_car_index = i - 1;
                state = '8';
                return;
            } else if (choice3 == '2'){
                state = '5';
                return;
            }
        }else if (Login == false){
            cout << "\nYou must Sign In first!!";
            cout << "\n1.Sign In\t\t2.Back\nYour choice :";cin >> choice2;
            if (choice2 == '1'){
                state = '2';
                return;
            }else if (choice2 == '2'){
                state = '1';
                return;
            }
        }
    }else if(choice == '2'){
        state = '5';
        return;
    }
}

void returnToMenuPage(){
    char back;
    cout << "\n1.Back \n2.Exit\n";
    cout << "Your choice : ";  cin >> back;
        if (back == '1'){
           state = '5';
           return ;
        } else if (back == '2'){
           state = '4';
           return ; 
        }
}

void loginPage(){
    string nama, key;
    char choice;
    bool login_success;
    cout << "Sign in as:\n1.Renter 2.Admin\nYour choice : ";cin >> login_choice;
    cout << "Name : "; 
    cin.ignore();
    getline(cin, nama);
    cout << "Password : "; cin >> key;
    if (login_choice == '1'){
        login_success = renter_database.SignInCheck(nama, key);
    }else if (login_choice == '2'){
        login_success = admin_database.SignInCheck(nama, key);
    }
    Login = login_success;
    if (login_success == true){
        if (login_choice == '1'){
            renter = Renter(nama, key);
            cout << '\n' << renter.getUsername() << " berhasil Login!!\n ";
            state = '5';
        return;
        }else if(login_choice == '2'){
            admin = Admin(nama,key);
            cout << '\n' << admin.getAdminId() << " berhasil Login!!\n ";
            state = '9';
        }
    } else {
        cout << "\nInvalid Username or Password\n";
        cout << "1.Try again\n2.Back to Main menu\nYour choice : ";cin >> choice;
        if(choice == '1'){
            state = '2';
            return;
        } else if (choice = '2'){
            state = '1';
            return;
        }
    }
}

void registPage(){
    string nama, password;
    char choice;
    cin.ignore();
    cout << "Name : ";
    getline(cin, nama);
    cout << "Password(No Space!) : ";cin >> password;
    Renter newRenter = Renter (nama, password);
    renter_database.saveRenter(newRenter.getString());
    cout << "\nRegistrasi " << newRenter.getUsername() << " berhasil!!\n";
        cout << "1.exit\n2.Back to Main menu\nYour choice : ";cin >> choice;
        if(choice == '1'){
            state = '4';
            return;
        } else if (choice = '2'){
            state = '1'; 
            return;
        }
}

void PaymentPage(){
    Payment payment;
    double day;
    char choice;
    cout << "Renting day(s): "; cin >> day;
    payment.setDay(day);
    payment.calculatePayment(car1.getPrice());
    cout << "=========================\n";
    cout << "TOTAL BILL : Rp." << payment.getBill();
    cout << "\n=========================\n";
    cout << "1.Pay\t2.Cancel\nYour choice: ";cin >> choice;
        if (choice == '1'){
                cout << "Your payment has been sucsesfull!\n";
                cout << "Screenshot this online ticket and show to\n our";
                cout << "staff when you have been at our rental center!!\n\n";
                cout << "============================================\n";
                cout << "              RENTAL TICKET                 \n";
                cout << "============================================\n";
                cout << "  Renter's Name : " << renter.getUsername() << '\n';
                cout << "  Car           : " << car1.getType() << '\n';
                cout << "  Total day     : " << payment.getDay() << '\n';
                cout << "  Total bill    : " << payment.getBill() << '\n';
                cout << "  Payment status: succes\n";
                cout << "============================================\n\n";
                Cars[rent_car_index].setStatus("Rented");
                car_database.updateCarStatus(Cars);
                
        }else if (choice == '2'){
            state = '5';
            return;
        }
    state = '5';
    return;
}

//state 9
void AdminPage(){
    cout << "=========ADMIN'S MENU=========\n";
    cout << "1. Add car\n";
    cout << "2. Car return\n";
    cout << "3. Delete car\n";
    cout << "4. Sign out\n";
    cout << "5. Exit\n";
    cout << "Your choice : ";
    char input;
    cin >> input;
    if (input == '1'){
            state = 'a';
           return ;
    } else if (input == '2'){
           state = 'c';
           return ; 
    } else if (input == '3'){
            state = 'b';        
            return;
    } else if (input == '4'){
            Login = false;
            state = '1';
            admin = Admin("admin", "-");
            return;
    }else if (input == '5'){
            state = '4';
            return;
    }
}

//state a
void AddCarPage(){
    char choice;
    admin.addCar(Cars);
    car_database.updateCarStatus(Cars);
    car1.showAllCars(Cars);
    cout << "1.Add more car\t2.Back\nYour choice : ";cin >> choice;
    if (choice == '1'){
        state = 'a';
        return;
    }else if(choice = '2'){
        state = '9';
        return;
    } 
}

//state b
void DeleteCarPage(){
    char choice;
    car1.showAllCars(Cars);
    admin.deleteCar(Cars);
    car_database.updateCarStatus(Cars);
    car1.showAllCars(Cars);
    cout << "1.Delete more car\t2.Back\nYour choice : ";cin >> choice;
    if (choice == '1'){
        state = 'b';
        return;
    }else if(choice = '2'){
        state = '9';
        return;
    } 
}

//state c
void ReturnCarPage(){
    char choice;
    car1.showAllCars(Cars);
    admin.editCarStatus(Cars);
    car_database.updateCarStatus(Cars);
    car1.showAllCars(Cars);
    cout << "1.Edit more car\t\t2.Back\nYour choice : ";cin >> choice;
    if (choice == '1'){
        state = 'c';
        return;
    }else if(choice = '2'){
        state = '9';
        return;
    } 
}
