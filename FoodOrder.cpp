#include "FoodOrder.hpp"
#include "InvalidInput.hpp"
#include <iostream>

using namespace std;

//constructor
FoodOrder::FoodOrder(string customerName, string date, string phone, float miles, string restaurantName)
        :DeliveryOrder(customerName, date, phone, miles)
{
    this->restaurantName = restaurantName;
    foodCount = 0;

    //output placing order for food
    cout << customerName << " placing order." <<endl;
}

//destructor
FoodOrder::~FoodOrder()
{
    cout << "FoodOrder destroyed." << endl;
};

void FoodOrder::printReceipt () const
{
    DeliveryOrder::printReceipt();
    cout << "\tOrdered Foods: " << foodCount << endl;
}

//this function will determine discount
float DeliveryOrder::VIPdiscount()
{
    float discount = 0;

    if(totalBalance > 50)
    {
        discount = (0.85);
    }

    if(totalBalance > 30)
    {
        discount = (0.9);
    }

    if(totalBalance > 20)
    {
        discount = (0.95);
    }
    
    if(totalBalance <= 20)
    {
        discount = (1);
    }

    return discount;
};

//logic that takes in order and calculates balance along with incrementing foodCount
void FoodOrder::addFood(string meal, int sides, bool b)
{

    //initialize menu variables
    string tcs = "Thick Cauliflower Steak";
    string rol = "Rack of Lamb";
    string oss = "Organic Scottish Salmon";
    string glr = "Grilled Lobster Risotto";

    //initialize other costs
    int soupCost = 6;
    int sideCost = 5;
    

   //if customer wants Thick Cauliflower Steak
    if(meal == tcs)
    {
        //wants soup
        if(b == true)
        {
            totalBalance += 18 + (sideCost*sides) + soupCost;
            foodCount++;
        }

        //does not want soup
        else
        {
            totalBalance += 18 + (sideCost*sides);
            foodCount++;
        }
    }
        
    //if customer wants Rack of Lamb
    else if(meal == rol)
    {
        //wants soup
        if(b == true)
        {
            totalBalance += 48 + (sideCost*sides) + soupCost;
            foodCount++;
        }

        //does not want soup
        else
        {
            totalBalance += 48 + (sideCost*sides);
            foodCount++;
        }
    }

    //if customer wants Organic Scottish Salmon
    else if(meal == oss)
    {
        //wants soup
        if(b == true)
        {
            totalBalance += 22 + (sideCost*sides) + soupCost;
            foodCount++;
        }

        //does not want soup
        else
        {
            totalBalance += 22 + (sideCost*sides);
            foodCount++;
        }
    }

    //if customer wants Grilled Lobster Risotto
    else if(meal == glr)
    {
        //wants soup
        if(b == true)
        {
            totalBalance += 38 + (sideCost*sides) + soupCost;
            foodCount++;
        }

        //does not want soup
        else
        {
            totalBalance += 38 + (sideCost*sides);
            foodCount++;
        }
    }

    //if user enters something not acceptable
    else
    {
        throw InvalidInput(meal);
    }
}