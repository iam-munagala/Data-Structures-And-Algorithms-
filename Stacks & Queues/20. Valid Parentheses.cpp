#include <bits/stdc++.h>
using namespace std;

bool validParenthesis(string s)
{
    stack<char> st;
    for (auto it : s)
    {
        if (it == '(' || it == '{' || it == '[')
        {
            st.push(it);
        }
        else
        {
            if (st.size() == 0)
                return false;
            char ch = st.top();
            st.pop();
            if ((it == ')' && ch == '(') || (it == '}' && ch == '{') || (it == ']' && ch == '['))
                continue;
            else
                return false;
        }
    }
    return st.empty();
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (validParenthesis(s))
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }
    return 0;
}

/*

time complexity : O(n)
space complexity : O(n)

*/