#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
using namespace std;
ll MOD = 1e9 + 7;

int priority(char x)
{
    if (x == '*' || x == '/')
    {
        return 2;
    }
    else if (x == '+'  || x == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    //cout.tie(0);
    string s;
    cin >> s;
    string res="";
    stack<char> st;
    for (int i = 0; i < (int)s.size();i++)
    {
        if (isalpha(s[i]))
        {   
            res += s[i];
        }
        else
        {
            if (st.empty() )
            {
                st.push(s[i]);
            }
            else
            {
                if (s[i] == '(')
                {
                    st.push(s[i]);
                }
                else if (s[i] == ')')
                {
                    while (st.top()!='(')
                    {
                        res += st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else
                {
                    while (!st.empty() && priority(st.top())>=priority(s[i]))
                    {
                        res += st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                        
                }
            }
        }
    }
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }
    cout << res;
    return 0;
}