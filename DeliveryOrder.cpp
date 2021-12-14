#include "DeliveryOrder.h"
#include <iostream>
#include <iomanip>

using namespace std;

//initilalizing static variables
float const DeliveryOrder::taxRate = 0.0887;
int const DeliveryOrder::deliveryRate = 2;
int DeliveryOrder::orderCount = 0;

//constructor
DeliveryOrder::DeliveryOrder(string customerName, string date, string phone, float miles)
{
    this->customerName = customerName;
    this->date = date;
    this->phone = phone;
    this->miles = miles;

    //initialize static value to 0
    this->totalBalance = 0;
    orderCount++;
}

//DeliveryOrder destructor
DeliveryOrder::~DeliveryOrder()
{
    cout << "DeliveryOrder destroyed." << endl;
};

//logic for printing out receipt
void DeliveryOrder::printReceipt () const
{
    cout << "Order Detail:" << "\n";
    cout << "\t" << this->customerName << "\n";
    cout << "\tDate: " << this->date << "\n";
    cout << "\tPhone: " << this->phone << "\n";
    cout << "\tTotal Balance: $" << setprecision(2) << fixed << this->totalBalance << endl;
}

//logic for getting balance
float DeliveryOrder::getBalance() const
{
    return (totalBalance * (1 + taxRate) + miles * deliveryRate);
}

//logic for getting order count
int DeliveryOrder::getOrderCount()
{
    return orderCount;
}