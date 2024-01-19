#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll sum1 = 0;
    ll sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 = max(1ll * 0, sum1 + a[i]);
        sum2 = max(sum2, sum1);
    }
    cout << sum2;
    return 0;
}