/*
Given a string s, find the length of the longest
substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int left = 0, right = 0, maxLen = 0;
        vector<int> mpp(256, -1);

        while(right<n){
            if(mpp[s[right]]!=-1){
                left = max(left,mpp[s[right]]+1);
            }
            mpp[s[right]]=right;
            maxLen = max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};
int main()
{
    int t;
    cin >> t;
    Solution sol;
    while (t--)
    {
        string s;
        cin >> s;
        cout << sol.lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}