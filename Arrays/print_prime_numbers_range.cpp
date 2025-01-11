#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int start, end, sum = 0;
        cin >> start >> end;
        Solution obj;
        for (int i = start; i <= end; i++)
        {
            if (obj.isPrime(i))
            {
                sum += i;
            }
        }
        cout << "Sum = " << sum << endl;
    }

    return 0;
}