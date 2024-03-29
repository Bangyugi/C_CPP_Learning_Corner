#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (st.empty())
            st.push(s[i]);
        else if (s[i] == st.top())
        {
            st.pop();
        }
        else
            st.push(s[i]);
    }
    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    if (res == "")
    {
        cout << "EMPTY";
        return 0;
    }
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}