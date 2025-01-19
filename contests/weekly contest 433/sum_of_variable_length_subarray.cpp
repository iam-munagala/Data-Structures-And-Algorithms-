#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums)
    {
        int n = nums.size();
        int total_sum = 0;
        int currentSum = 0;

        for (int i = 0; i < n; i++)
        {
            int start = max(0, i - nums[i]);
            currentSum += nums[i];

            if (start > 0)
            {
                currentSum -= nums[start - 1];
            }

            total_sum += currentSum;
        }

        return total_sum;
    }
};

int main()
{
    int t;
    cin >> t;
    Solution sol;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << sol.subarraySum(arr) << endl;
    }
    return 0;
}
