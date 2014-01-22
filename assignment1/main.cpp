#include "assignment1.h"

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    cout << "Enter a number: ";
    int a;
    cin >> a;
    cout << "\n";
    cout << "Enter another number: ";
    int b;
    cin >> b;
    cout << "\n";
    
    int gcd = GCD(a,b);
    int lcm = LCM(a, b, gcd);
    cout << "The GCD and LCM between two integers " <<a<< " and " <<b<< " are: " << gcd << " and " << lcm << "\n";
    
   
    
    return 0;
}