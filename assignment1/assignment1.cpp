#include "assignment1.h"
#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    while (b != 0) 
    {
        if (a > b)
            a = a-b;
        else
            b = b-a;
    }
    return a;
}

int LCM(int a, int b, int gcd)
{
    int top = a*b;
    int lcm = top/gcd;
    return lcm;
}

