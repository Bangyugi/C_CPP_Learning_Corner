#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < (int)s.size(); i++)
    {
        mp[s[i]]++;
    }
    int cntEven = 0;
    for (auto x : mp)
    {
        if (x.second % 2 != 0)
        {
            cntEven++;
        }
    }
    if (cntEven == 0)
    {
        cout << 1;
    }
    else
    {
        if (cntEven % 2 == 0)
        {
            cout << 2;
        }
        else
        {
            cout << 1;
        }
    }
    return 0;
}