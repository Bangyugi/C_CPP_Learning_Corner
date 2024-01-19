#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    set<int> se;
    for (auto x : s)
    {
        se.insert(x);
    }
    map<int, int> mp;
    long long l = 0;
    long long ans = INT_MAX;
    int cnt = 0;
    int n = se.size();
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
        if (mp[s[i]] == 1)
        {
            cnt++;
        }
        while (cnt >= n)
        {
            ans = min(ans, i - l + 1);
            mp[s[l]]--;
            if (mp[s[l]] == 0)
            {
                cnt--;
            }
            l++;
        }
    }
    cout << ans;
}