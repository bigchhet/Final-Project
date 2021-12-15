#include "BobaOrder.hpp"
#include "InvalidInput.hpp"
#include <iostream>

using namespace std;

//constructor
BobaOrder::BobaOrder(string customerName, string date, string phone, float miles, string shopName)
        :DeliveryOrder(customerName, date, phone, miles)
{
    this->shopName = shopName;
    drinksCount = 0;

    //output placing order for boba
    cout << customerName << " placing order." <<endl;
}

//BobaOrder destructor
BobaOrder::~BobaOrder()
{
    cout << "BobaOrder destroyed." << endl;
};

//logic for printing receipt with new info
void BobaOrder::printReceipt () const
{
    DeliveryOrder::printReceipt();
    cout << "\tOrdered Drinks: " << drinksCount << endl;
}

//function will compare input and alter totalBalance / drinksCount
void BobaOrder::addDrink(string s, bool b, int c)
{
    //defining the boba names
    string gtc = "Green Tea Latte";
    string bsbm = "Brown Sugar Boba Milk";
    string bspm = "Brown Sugar Pearl Milk";

    float bobaCost = 1.50;
    //if customer wants Green Tea Latte
    if(s == gtc)
    {
        //wants boba
        if(b == true)
        {
            totalBalance += (c * (10.9 + bobaCost));
            drinksCount += c;
        }

        //does not want boba
        else
        {
            totalBalance += (10.9*c);
            drinksCount += c;               
        }
    }
    
    //if customer wants Brown Sugar Boba Milk
    else if(s == bsbm)
    {
        //wants boba
        if(b == true)
        {
            totalBalance += (c * (11.9 + bobaCost));
            drinksCount += c;
        }

        //does not want boba
        else
        {
            totalBalance += (11.9*c);
            drinksCount += c;
        }
    }

    //if customer wants Brown Sugar Pearl Milk
    else if(s == bspm)
    {
        //wants boba
        if(b == true)
        {
            totalBalance += (c * (12.90 + bobaCost));
            drinksCount += c;
        }

        //does not want boba
        else
        {
            totalBalance += (12.9*c);
            drinksCount += c;
        }
    }

    //if user enters something not acceptable
    else
    {
        throw InvalidInput(s);
    }       
}

//overrding vip discount
float BobaOrder::VIPdiscount()
{
    float discount = 0;

    if(drinksCount > 10)
    {
        discount = (0.85);
    }

    if(drinksCount > 5)
    {
        discount = (0.9);
    }

    if(drinksCount > 2)
    {
        discount = (0.95);
    }
    
    if(drinksCount <= 2)
    {
        discount = (1);
    }

    return discount;

};