#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (!isalpha(s[i]))
        {
            if (s[i] == ')')
            {
                if (st.top() != '(')
                {
                    while (!st.empty() && st.top() != '(')
                    {
                        st.pop();
                    }
                    st.pop();
                }
                else
                {
                    cout << "YES";
                    return 0;
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    if (st.empty())
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    return 0;
}