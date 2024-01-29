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
    return 0;
    string s;
    stack<string> st;
    while (cin>>s)
    {
        st.push(s);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    
}