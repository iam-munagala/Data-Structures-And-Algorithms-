#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findKey(int input1, int input2, int input3)
{
    int hundredsDigitInput1 = (input1 / 100) % 10;
    int tensDigitInput2 = (input2 / 10) % 10;
    int largestDigitInput3 = max({input3 % 10, (input3 / 10) % 10, (input3 / 100) % 10, input3 / 1000});
    return (hundredsDigitInput1 * tensDigitInput2) - largestDigitInput3;
}

int main()
{
    int input1 = 3521, input2 = 2452, input3 = 1352;
    cout << findKey(input1, input2, input3);
    return 0;
}