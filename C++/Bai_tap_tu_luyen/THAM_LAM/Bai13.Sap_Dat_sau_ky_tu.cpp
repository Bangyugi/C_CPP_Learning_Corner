#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        mp[s[i]]++;
        ans = max(ans, mp[s[i]]);
    }
    if ((ans - 1) <= (s.size() - ans))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}