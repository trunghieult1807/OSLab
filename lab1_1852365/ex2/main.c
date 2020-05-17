#include <iostream>
#include "sum.h"
#include "sub.h"
using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    cout << "Input a! \n";
    cin >> a;
    cout << "Input b! \n";
    cin >> b;
    cout << "sum a and b:" << sum(a,b) << "\n";
    cout << "sub a and b:" << sub(a,b) << "\n";
}
