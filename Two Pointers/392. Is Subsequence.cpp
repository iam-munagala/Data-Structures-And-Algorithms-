/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).



Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false


Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.

*/

#include <bits/stdc++.h>
using namespace std;

class isSubSequence
{
public:
    bool isSubsequence(string &s1, string &s2)
    {
        int i = 0, j = 0;
        while (i < s1.length() && j < s2.length())
        {
            if (s2[j] == s1[i])
            {
                i++;
            }
            j++;
        }
        return i == s1.length();
    }
};


/*
                     i 
        s = i=   a  b c  length = 3
        t =  j = a h b g d c lenght = 6 

*/

int main()
{

    int testcases;
    cin >> testcases;
    cin.ignore();
    isSubSequence sub;
    while (testcases--)
    {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);

        bool result = sub.isSubsequence(s1, s2);
        cout << (result ? "true" : "false");
    }

    return 0;
}