#include <iostream>
#include <string>
#include "InvalidInput.h"

using namespace std;

//logic for when a user enters an unacceptable input in either addDrink or addFood
InvalidInput::InvalidInput(string s) : message()
{
    message = "Invalid input \"" + s + "\".";
}

void InvalidInput::cause()
{
    cout << message;
}

