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
    int n;
    cin >> n;
    stack<int> st;
    while(n--)
    {
        string s;
        cin >>  s;
        if (s == "push")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (s=="top")
        {
            if (st.empty())
            {
                cout << "NONE" <<endl;
            }
            else
            {
                cout << st.top() << endl;
            }
        }
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
    }
    return 0;
}