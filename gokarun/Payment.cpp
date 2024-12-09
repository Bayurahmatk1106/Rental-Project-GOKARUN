#include "Payment.h"
#include "Database.h"

void Payment::setDay (double day){
    Day = day;
}

double Payment::getBill(){
    return Bill;
}

double Payment::getDay(){
    return Day;
}

void Payment::calculatePayment(double price){
    Bill = getDay() * price;
}