/*

Given two strings s and t, return true if t is an
anagram of s, and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false


Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string &s1, string &s2)
    {
        if (s1.size() != s2.size())
            return false;
        map<char, int> freq;
        for (char c : s1)
        {
            freq[c]++;
        }
        for (char c : s2)
        {
            freq[c]--;
        }
        for (auto &it : freq)
        {
            if (it.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solution sol;
        string s1, s2;
        cin >> s1 >> s2;
        cout << (sol.isAnagram(s1, s2)?"true":"false") << endl;
    }
    return 0;
}

/*

Time Complexity: O(n), where n is the length of the input strings.
Space Complexity: O(1) (due to the constant size of the frequency map).

*/