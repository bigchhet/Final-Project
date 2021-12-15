#include <iostream>
#include <string>
#include <math.h>
#include "DeliveryOrder.hpp"

using namespace std;

#ifndef FoodOrder_H
#define FoodOrder_H

//this class will need to be abstract
class FoodOrder : public DeliveryOrder
{
    private:
        //declare private attributes
        string restaurantName;
        int foodCount;

    public:
        //constructor
        FoodOrder(string, string, string, float, string);

        //destructor
        ~FoodOrder();

        //overriding functions
        void printReceipt() const;

        //addFood function with default parameters
        void addFood(string, int = 0, bool = false);    
};

#endif

