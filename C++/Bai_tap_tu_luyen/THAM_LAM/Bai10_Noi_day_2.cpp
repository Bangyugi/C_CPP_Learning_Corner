#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    ll a[n];
    multiset<ll> se;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        se.insert(a[i]);
    }
    ll ans = 0;
    while (se.size() >= 2)
    {
        auto it1 = se.end();
        it1--;
        auto it2 = it1;
        it2--;
        ll sum = *it1 % MOD + *it2 % MOD;
        ans += sum % MOD;
        ans %= MOD;
        se.erase(it1);
        se.erase(it2);
        se.insert(sum);
    }
    cout << ans;

    return 0;
}