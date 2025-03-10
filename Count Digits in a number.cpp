// count digits in a number

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int count = 0;

    if(num==0) count=1;
    while (num > 0)
    {
        num = num / 10;
        count++;
    }
    cout<<"Number of digits : "<<count<<endl;
}