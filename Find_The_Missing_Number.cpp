/*

Find the Missing Number

Given an array arr[] of size N-1 with integers in the range of [1,N],
the task is to find the missing number from the first N integers

Note : There are no duplicates in the list

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.


Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.


Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

*/

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int expectedSum = (n * (n + 1) / 2);
    return expectedSum - sum;
}

int main()
{
    vector<int> arr;
    arr.push_back(9);
    arr.push_back(6);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(7);
    arr.push_back(0);
    arr.push_back(1);
    cout << "Missing Number is : " << missingNumber(arr);
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity : O(1);
*/