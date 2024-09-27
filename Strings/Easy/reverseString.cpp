#include <bits/stdc++.h>
using namespace std;

void reverseString(string &s)
{
    int low = 0;
    int high = s.size() - 1;
    while (low <= high)
    {
        swap(s[low++], s[high--]);
    }
}

int main()
{
    string s = "hello";
    reverseString(s);
    cout << s;
}

/*

Time Complexity :O(n)
Space Complexity : O(1)

*/