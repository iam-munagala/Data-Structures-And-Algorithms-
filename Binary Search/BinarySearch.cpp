#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == x)
            return mid;
        else if (nums[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 7;
    int result = binarySearch(nums, element);
    cout << "Element is found at index : " << result << endl;
}