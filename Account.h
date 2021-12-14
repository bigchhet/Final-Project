#include <iostream>
#include <string>
#include <math.h>
#include "DeliveryOrder.h"

using namespace std;

#ifndef Account_H
#define Account_H

//this class will need to be abstract
class Account
{
    private:
        //declare private attributes
        string username;
        string status;

    public:
        //Default constructor
        Account(string, string = "Regular");

        //destructor
        ~Account();

        //getter function that is constant
        string getStatus() const;  
};

#endif

