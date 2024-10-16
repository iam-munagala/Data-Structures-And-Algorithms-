/*
Find the maximum or minimum element in an array

Example :

Input:
arr = {12,223,1,4,5,6}

Expected Output :

Minimum Element of Array is : 1
Maximum Element of Array is : 223

*/

#include <bits/stdc++.h>
using namespace std;

int getMinElement(int arr[], int n)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        res = min(res, arr[i]);
    }
    return res;
}

int getMaxElement(int arr[], int n)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, arr[i]);
    }
    return res;
}

int main()
{
    int arr[] = {12, 223, 1, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Element of Array is " << getMinElement(arr, n) << "\n";
    cout << "Maximum Element of Array is " << getMaxElement(arr, n) << "\n";
    return 0;
}

/*

Time Complexity : O(n);
Space Complexity : O(1);

*/