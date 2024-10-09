/*
Check if given strings are rotations of each other or not
Last Updated : 13 May, 2024
Given a string s1 and a string s2, write a function to check whether s2 is a rotation of s1.

Examples:

Input: S1 = ABCD, S2 = CDAB
Output: Strings are rotations of each other



Input: S1 = ABCD, S2 = ACBD
Output: Strings are not rotations of each other

*/

#include <bits/stdc++.h>
using namespace std;

bool isStringRotated(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;
    string temp = s1 + s2;
    if (temp.find(s2) != string::npos)
        return true;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout<<isStringRotated(s1,s2);
    return 0;
}