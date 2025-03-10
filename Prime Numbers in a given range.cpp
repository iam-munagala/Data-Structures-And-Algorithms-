#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
};

int main()
{
    int testcases;
    cin >> testcases;
    Solution sol;  // Create object once
    while (testcases--)
    {
        int low, high;
        cin >> low >> high;
        cout << "Prime Numbers between " << low << " and " << high << " : ";
        bool found = false;
        for (int i = low; i <= high; i++)
        {
            if (sol.isPrime(i))
            {
                cout << i << " ";
                found = true;
            }
        }
        if (!found)
            cout << "None";
        cout << endl;
    }
    return 0;
}
