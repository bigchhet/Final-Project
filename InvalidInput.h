#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#ifndef InvalidInput_H
#define InvalidInput_H

class InvalidInput
{
    private:
        string message;
    public:
        //Constructor    
        InvalidInput(string);

        //only function required in class
        void cause();
};

#endif

