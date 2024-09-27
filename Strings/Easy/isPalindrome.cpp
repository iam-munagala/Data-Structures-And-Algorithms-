

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s)
{
    int low = 0;
    int high = s.size() - 1;
    while (low <= high)
    {
        if (s[low++] != s[high--])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "malayalam";
    cout << isPalindrome(s);
}