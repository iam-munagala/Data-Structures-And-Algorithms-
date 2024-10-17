#include <bits/stdc++.h>
using namespace std;

void findDuplicates(vector<int> &nums)
{
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }
    cout << "Duplicate elements are: ";
    for (const auto &it : mpp)
    {
        if (it.second > 1)
        {
            cout << it.first << " ";
        }
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1, 4, 5};
    findDuplicates(nums);

    return 0;
}
