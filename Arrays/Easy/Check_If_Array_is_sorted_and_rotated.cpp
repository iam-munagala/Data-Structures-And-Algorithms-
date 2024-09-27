#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }
    if (nums[n - 1] > nums[0])
    {
        count++;
    }
    return count <= 1;
}

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(2);

    cout << "The given array is sorted in circular manner: " << (isSorted ? "Yes" : "No") << endl;
    return 0;
}
/*

Time complexity : O(n);
space complexity: O(1);

*/