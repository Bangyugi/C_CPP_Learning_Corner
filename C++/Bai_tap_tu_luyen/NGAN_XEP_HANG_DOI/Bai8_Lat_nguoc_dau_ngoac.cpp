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
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                ans++;
                st.push('(');
            }
            else
            {
                st.pop();
            }
        }
    }
    cout << st.size() / 2 + ans;
    return 0;
}