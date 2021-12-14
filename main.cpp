#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include "BobaOrder.h"
#include "Account.h"
#include "DeliveryOrder.h"
#include "FoodOrder.h"
#include "InvalidInput.h"
#include <iomanip>

using namespace std;

//applyDiscount() function
float applyDiscount(DeliveryOrder* d, Account& a)
{
    float discount = 0;

    //logic for showing discount for owner
    if (a.getStatus() == "Owner")
    {
       discount = (d->getBalance() * 0.1);
    }

    //logic for showing discount for VIP
    else if (a.getStatus() == "VIP")
    {
        discount = (d->getBalance() * d->VIPdiscount());
    }

    //if regular customer, just return unchanged total balance
    else if (a.getStatus() == "Regular")
    {
        discount = (d->getBalance());
    }

    return discount;
}


int main()
{
    //creating pointers
    DeliveryOrder* order;
    FoodOrder * food;

    //Create Account Objects
    Account kev ("Kevin", "VIP");
    Account stu ("Stuart", "Owner"); //idk how to make this a constant account?
    Account bob ("Bob");

    //create BobaOrder for Kevin
    BobaOrder Kevin ("Kevin", "11/20/2021", "123-456-0000", 10.4, "Tiger Sugar");

    //attempt to add drink
    try 
    {
        Kevin.addDrink("Green Tea Latte");
        Kevin.addDrink("Brown Sugar Pearl Milk", false);
        Kevin.addDrink("Brown Sugar Boba Milk", false, 2);
        Kevin.addDrink("Iron Goddess");
    }   
    //logic for calling invalid input
    catch(InvalidInput &e)
    {
        e.cause();
        std::cout << endl;
        std::cout << "Not serving requested drinks. Drink order ignored." << endl;
    }
    
    std::cout << endl;

    //print the receipt for Kevin
    Kevin.BobaOrder::printReceipt();
    std::cout << "Balance: $" << Kevin.DeliveryOrder::getBalance() << endl;
    
    //have the DeliveryOrder pointer pointing at Kevin object
    order = &Kevin;
    std::cout << "Discounted Balance: $" << setprecision(2) << fixed << applyDiscount(order, kev) << endl;

    //putting seperation between orders
    std::cout << endl;
    std::cout << endl;
    
    //create FoodOrder for Stuart
    FoodOrder Stuart("Stuart", "11/20/2021", "123-456-1111", 25.5, "Tavern Green");

    //attempt to add food
    try
    {
        Stuart.addFood("Thick Cauliflower Steak", 1, true);
        Stuart.addFood("Organic Scottish Salmon", 0, false);
        Stuart.addFood( "Rack of Lamb", 0, true);
    }
    catch(InvalidInput &e)
    {
        e.cause();
        std::cout << endl;
        std::cout << "Not serving requested food. Food order ignored." << endl;
    }

    //print the receipt for Stuart
    Stuart.FoodOrder::printReceipt();
    std::cout << "Balance: $" << Stuart.DeliveryOrder::getBalance() << endl;

    //have the DeliveryOrder pointer pointing at Stuart object
    order = &Stuart;
    std::cout << "Discounted Balance: $" << setprecision(2) << fixed << applyDiscount(order, stu) << endl;;

    //putting seperation between orders
    std::cout << endl;
    std::cout << endl;

    std::cout << "Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart." << endl;

    //have the FoodOrder pointer pointing at Stuart object
    food = &Stuart;
    food->FoodOrder::printReceipt();
    std::cout << "Balance: $" << food->getBalance() << endl;
    std::cout << "Discounted Balance: $" << setprecision(2) << fixed << applyDiscount(food, bob) << endl;;
    
    //show Bob is upset from not getting ideal discount 
    std::cout << "Bob upset, cancelling order :(" << endl;

    std::cout << endl;

    //output total orders placed
    std::cout << "Total order placed: " << DeliveryOrder::getOrderCount() << "." << endl;
    
    std::cout << endl;

    return 0;
}