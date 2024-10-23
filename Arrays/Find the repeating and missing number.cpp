/*

Given an unsorted array of size n. Array elements are in the range of 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

Examples: 

Input: arr[] = {3, 1, 3}
Output: Missing = 2, Repeating = 3
Explanation: In the array, 2 is missing and 3 occurs twice 


Input: arr[] = {4, 3, 6, 2, 1, 1}
Output: Missing = 5, Repeating = 1



*/



#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    long long n = a.size();
    long long sum_of_numbers = (n * (n + 1)) / 2;
    long long sum_of_squares = (n * (n + 1) * (2 * n + 1)) / 6;

    long long s = 0;
    long long s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        s2 += (long long)a[i] * a[i];
    }

    long long val1 = s - sum_of_numbers;
    long long val2 = s2 - sum_of_squares;
    val2 = val2 / val1;

    long long repeating = (val1 + val2) / 2;
    long long missing = repeating - val1;

    return {(int)repeating, (int)missing};
}



int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        vector<int> result = findMissingRepeatingNumbers(nums);
        cout << "Repeating: " << result[0] << ", Missing: " << result[1] << endl; // added endl for proper formatting
    }

    return 0;
}
