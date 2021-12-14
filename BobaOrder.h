#include <iostream>
#include <string>
#include <math.h>
#include "DeliveryOrder.h"

using namespace std;

#ifndef BobaOrder_H
#define BobaOrder_H

//this class is inherited from DeliveryOrder Class
class BobaOrder : public DeliveryOrder
{
    private:
        //declare private attributes
        string shopName;
        int drinksCount; 

    public:
        //constructor
        BobaOrder(string, string, string, float, string);

        //destructor
        ~BobaOrder();

        //overriding functions
        void printReceipt() const;
        float VIPdiscount();

        //add drink function with default parameters
        void addDrink(string, bool = true, int = 1); 
};

#endif

