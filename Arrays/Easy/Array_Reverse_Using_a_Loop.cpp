#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        cout << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    reverseArray(arr, 0, n - 1);
    cout << "Reversed Array is :" << endl;
    printArray(arr, n);
    return 0;
}

/*
 Time Complexity : O(n)
 Space Complexity: O(1)
*/