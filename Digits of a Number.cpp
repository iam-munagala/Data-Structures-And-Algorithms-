/*

Display the digits of a number

input : N ( 1234)

output : 1 2 3 4

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int counter = 0;
    int temp = n;
    while (temp != 0)
    {
        temp = temp / 10;
        counter++;
    }

    int div = pow(10,counter-1);
    while(div != 0)
    {
        int q = n / div;
        cout << q << " ";
        n = n % div;
        div = div / 10;
    }
    return 0;
}