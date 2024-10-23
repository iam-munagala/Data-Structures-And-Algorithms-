/*

Given a string S, the task is to print all the duplicate characters with their occurrences in the given string.

Example:

Input: S = “geeksforgeeks”
Output:
e, count = 4
g, count = 2
k, count = 2
s, count = 2

Explanation: g occurs 2 times in the string, k occurs 2 times in the string, s occurs 2 times in the string while e occurs 4 times in the string rest of the characters have unique occurrences.

*/

#include <bits/stdc++.h>
using namespace std;

/*
    geeks for geekss 
     
     g - 1 2
     e -1 2 3 3
     k -1  2 
     s - 1 2 
     f -1 
     o -1 
     r -1 

*/

void findDuplicates(string &str)
{
    unordered_map<char, int> count;
    for (int i = 0; i < str.size(); i++)  
    {
        count[str[i]]++;
    }
    for (auto it : count)
    {
        if (it.second > 1)
        {
            cout << it.first << ",count = " << it.second << endl;
        }
    }
}

int main()
{
    int testcases;
    cin >> testcases;
    cin.ignore();
    while (testcases--)
    {
        string str;
        getline(cin, str);
        findDuplicates(str);
    }
    return 0;
}