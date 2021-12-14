#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#ifndef DeliverOrder_H
#define DeliverOrder_H

//this class will need to be abstract
class DeliveryOrder
{
    private:
        //declare private attributes
        string customerName;
        string date;
        string phone;
        float miles;

        //declare static values
        static int orderCount;
        static const float taxRate;
        static const int deliveryRate;

    protected:
        //protected variable for only inherited classes
        float totalBalance;

    public:
        //constructor
        DeliveryOrder(string, string, string, float);

        //destructor
        virtual ~DeliveryOrder();

        //the four required functions
        void printReceipt() const;
        float getBalance() const;
        static int getOrderCount();
        virtual float VIPdiscount();    
};

#endif

