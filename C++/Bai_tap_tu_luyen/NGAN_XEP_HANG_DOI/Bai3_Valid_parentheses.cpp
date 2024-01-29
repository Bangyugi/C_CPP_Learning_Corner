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
    stack<char> st;
    for (int i = 0; i < (int)s.size();i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                cout << "NO";
                return 0;
            }
            else 
            {
                if (s[i] == ')' && st.top() =='(')
                {
                    st.pop();
                }
                else if (s[i] == ']' && st.top() =='[')
                {
                    st.pop();
                }
                else if (s[i] == '}' && st.top() =='{')
                {
                    st.pop();
                }
                else
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    if (st.empty())
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
        return 0;
}