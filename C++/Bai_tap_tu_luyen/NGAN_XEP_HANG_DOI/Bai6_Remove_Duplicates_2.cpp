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
    int k;
    cin >> k;
    int dem = 0;
    stack<char> st;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
            dem++;
        }
        else
        {
            if (s[i] == st.top())
            {
                st.push(s[i]);
                dem++;
                if (dem == k)
                {
                    while (dem > 0)
                    {
                        st.pop();
                        dem--;
                    }
                }
            }
            else
            {
                st.push(s[i]);
                dem = 1;
            }
        }
    }
    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    if (res == "")
    {
        cout << "EMPTY";
        return 0;
    }
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}