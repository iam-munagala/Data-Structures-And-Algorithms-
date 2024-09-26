/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]


Constraints:

 1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1


*/

#include <bits/stdc++.h>
using namespace std;

void moveZeroesToEnd(vector<int> &arr)
{
    int n = arr.size();
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[index++] = arr[i];
        }
    }
    for (int i = index; i < n; i++)
    {
        arr[i] = 0;
    }
}
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {0, 1, 0, 3, 12};
    moveZeroesToEnd(arr);
    printArray(arr);
    return 0;
}

/*

Time Complexity: O(n)
Space Complexity : O(1)

*/