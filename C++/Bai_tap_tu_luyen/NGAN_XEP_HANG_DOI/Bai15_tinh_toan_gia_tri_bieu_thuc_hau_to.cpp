#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    //cout.tie(0);
    string s;
    cin >> s;
    stack<ll> st;
    for (int i = 0; i < (int)s.size();i++)
    {
        if (isdigit(s[i]))
            st.push(s[i] - '0');
        else
        {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            if (s[i] == '+')
            {
                st.push(num1 + num2);
            }
            if (s[i] == '-')
            {
                st.push(num1 - num2);
            }
            if (s[i] == '*')
            {
                st.push(num1 * num2);
            }
            if (s[i] == '/')
            {
                st.push(num1 / num2);
            }
        }
    }
    cout << st.top();
    return 0;
}