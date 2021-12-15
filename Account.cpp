#include "Account.hpp"
#include <iostream>
#include "DeliveryOrder.hpp"

using namespace std;

//constructor
Account::Account(string customerName, string status)
{
    this->username = username;
    this->status = status;
}

//account destructor
Account::~Account()
{
    cout << "Account removed." << endl;
};

//logic for getting account status
string Account::getStatus() const
{
    return this->status;
}    
