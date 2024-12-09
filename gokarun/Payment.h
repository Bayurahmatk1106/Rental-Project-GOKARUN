#ifndef _PAYMENT_H
#define _PAYMENT_H

class Payment {
public:
    void setDay (double day);

    double getBill();

    double getDay();

    void calculatePayment(double price);

private: 
    double Bill;
    double Day;
};

#endif //_PAYMENT_H