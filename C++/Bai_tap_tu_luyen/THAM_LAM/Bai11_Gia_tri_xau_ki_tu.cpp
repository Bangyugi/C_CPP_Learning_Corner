#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    ll t, k;
    string s;
    cin >> t;
    while (t--)
    {
        ll ans = 0;
        map<char, ll> mp;
        vector<ll> v;
        cin >> k;
        cin >> s;
        for (ll i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        priority_queue<ll> pq;
        for (auto x : mp)
        {
            pq.push(x.second);
        }
        while (k > 0)
        {
            ll temp = pq.top();
            pq.pop();
            temp--;
            k--;
            pq.push(max(temp, 1ll*0));
        }
        while (!pq.empty())
        {
            ans += pq.top() * pq.top();
            pq.pop();
        }
        cout << ans << endl;
    }
    return 0;
}