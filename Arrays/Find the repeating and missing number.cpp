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
