#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

ll binpow(ll n, ll k)
{
    if (k == 1)
        return n;
    ll x = binpow(n, k / 2);
    if (k % 2 == 0)
    {
        return x % MOD * x % MOD;
    }
    else
    {
        return x % MOD * x % MOD * n % MOD;
    }
}

int main()
{
    ll n;
    cin >> n;
    cout << binpow(1ll * 2, n - 1);
    return 0;
}