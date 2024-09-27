/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.



Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105

*/

#include <bits/stdc++.h>
using namespace std;

void rotateArrayBrute(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n == 0)
        return;

    k = k % n;

    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }

    arr = temp;
}

/*

Time Complexity : O(n)
Space Complexity: O(n)

*/

void rotateArray(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n == 0)
        return;
    k = k % n;
    if (k == 0)
        return;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    // arr.push_back(8);
    int k = 3;
    // rotateArray(arr, k);
    printArray(arr);
    rotateArrayBrute(arr, k);

    printArray(arr);
    return 0;
}

/*

Time Complexity :O(n)
Space Complexity :O(1)
*/