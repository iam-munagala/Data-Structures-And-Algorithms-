#include <bits/stdc++.h>
using namespace std;

// Space complexity is O(1)
void mergeOptimalSolution(vector<int> &arr1, vector<int> &arr2)
{
    int m = arr1.size();
    int n = arr2.size();
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[k--] = arr1[i--];
        }
        else
        {
            arr1[k--] = arr2[j--];
        }
    }
    while (j >= 0)
    {
        arr1[k--] = arr2[j--];
    }
}

void merge(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
{
    int m = arr1.size();
    int n = arr2.size();
    int i = 0, j = 0, k = 0;

    arr3.resize(m + n);

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < m)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < n)
    {
        arr3[k++] = arr2[j++];
    }
}

void printArray(vector<int> &arr3)
{
    int n = arr3.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(3);
    arr1.push_back(5);
    arr1.push_back(7);
    arr1.push_back(9);
    vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(4);
    arr2.push_back(6);
    arr2.push_back(8);

    vector<int> arr3;

    merge(arr1, arr2, arr3);
    printArray(arr3);
    mergeOptimalSolution(arr1, arr2);

    printArray(arr3);

    return 0;
}

/*

Time Complexity : O(m+n)
Space Complexity : O(m+n)

*/