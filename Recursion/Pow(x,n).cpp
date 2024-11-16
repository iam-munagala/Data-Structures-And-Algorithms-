#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0)
            nn = -1 * nn;
        while (nn)
        {
            if (nn % 2)
            {
                ans = ans * x;
                nn = nn - 1;
            }
            else
            {
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0)
            ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        double x;
        int n;
        cin >> x >> n;

        Solution obj;
        double ans = obj.myPow(x, n);
        cout << ans << endl;
    }

    return 0;
}