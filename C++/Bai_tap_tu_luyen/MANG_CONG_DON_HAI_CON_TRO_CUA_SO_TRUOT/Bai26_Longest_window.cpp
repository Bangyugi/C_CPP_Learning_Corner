#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    map<int, int> mp;
    long long l = 0;
    long long ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
        while (mp[s[i]] > 1)
        {
            mp[s[l]]--;
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
}