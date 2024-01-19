#include <bits/stdc++.h>
#include <deque>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        pq.push(x);
    }
    ll ans = 0;
    while (pq.size() > 1)
    {
        ll top1 = pq.top();
        pq.pop();
        ll top2 = pq.top();
        pq.pop();
        ll temp = top1 + top2;
        ans += (temp) % MOD;
        ans %= MOD;
        pq.push((temp));
    }
    cout << ans << endl;
    return 0;
}
