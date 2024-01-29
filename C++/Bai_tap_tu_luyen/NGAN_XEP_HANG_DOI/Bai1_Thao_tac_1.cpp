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
    stack<int> st;
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else
        {
            if (st.empty())
            {
                cout << "EMPTY" << endl;
            }
            else
            {
                stack<int> temp;
                while(!st.empty())
                {
                    temp.push(st.top());
                    st.pop();
                }
                while (!temp.empty())
                {
                    cout << temp.top() << " ";
                    st.push(temp.top());
                    temp.pop();
                }
                cout << endl;
            }
        }
    }
    
    return 0;
}