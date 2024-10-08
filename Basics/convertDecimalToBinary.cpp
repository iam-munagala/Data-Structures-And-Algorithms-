#include <bits/stdc++.h>
using namespace std;

string convertDecimalToBinary(int n)
{
    if (n == 0)
    {
        return "0";
    }
    string res = "";
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res += '1';
        }
        else
        {
            res += '0';
        }
        n = n / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int n = 13;
    string result = convertDecimalToBinary(n);
    cout << result;
}

/*

time complexity: O(n)
space complexity : O(n)

*/