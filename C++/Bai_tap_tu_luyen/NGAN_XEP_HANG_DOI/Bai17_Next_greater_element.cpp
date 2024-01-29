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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<int> st;
    vector<int> v;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            v.push_back(-1);
            st.push(a[i]);
        }
        else if (a[i] < st.top())
        {
            v.push_back(st.top());
            st.push(a[i]);
        }
        else
        {
            while (!st.empty() && a[i] >= st.top())
            {
                st.pop();
            }
            if (st.empty())
                v.push_back(-1);
            else
                v.push_back(st.top());
            st.push(a[i]);
        }
    }
    reverse(v.begin(), v.end());
    for (auto x: v)
    {
        cout << x << " ";
    }
    return 0;
}