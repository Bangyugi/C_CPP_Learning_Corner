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
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] != '*' && s[i] != '/' && s[i] != '+' && s[i] != '-')
        {
            
            st.push(string(1,s[i]));
        }
        else
        {
            string t = st.top();
            st.pop();
            t = "(" + t + s[i] + st.top() + ")";
            st.pop();
            st.push(t);
        }
    }
    cout << st.top();
    return 0;
}