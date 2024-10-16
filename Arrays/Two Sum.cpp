#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> mpp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end())
        {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}

int main()
{
    cout << "Two sum" << endl;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int target = 11;
    vector<int> result = twoSum(nums, target);
    cout << result[0] << ' ' << result[1] << endl;
    return 0;
}