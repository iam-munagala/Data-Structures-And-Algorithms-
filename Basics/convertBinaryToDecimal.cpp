#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(string num)
{
    int decimalValue = 0;
    int base = 1;
    int n = num.length();
    for (int i = n - 1; i >= 0; i--)
    {
        if (num[i] == '1')
        {
            decimalValue += base;
        }
        base = base * 2;
    }
    return decimalValue;
}

int main()
{
    string num = "1101";
    cout << binaryToDecimal(num) << endl;
}