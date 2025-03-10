#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int low = 0;
    int high = 1;
    int result;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // sum += low;
        cout << low << endl;
        result = low + high;
        low = high;
        high = result;
    }
    // cout << sum;

    return 0;
}