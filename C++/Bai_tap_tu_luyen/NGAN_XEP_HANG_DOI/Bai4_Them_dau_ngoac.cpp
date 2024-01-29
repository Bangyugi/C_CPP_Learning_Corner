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
    int res = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            if (s[i] == ')' && st.top() == '(')
            {
                res += 2;
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    cout << (int)s.size() - res;
    return 0;
}