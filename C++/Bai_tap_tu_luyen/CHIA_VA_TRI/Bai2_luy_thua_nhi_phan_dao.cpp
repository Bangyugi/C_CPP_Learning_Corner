#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

ll binpow(ll a, ll b)
{
    if (b == 1)
    {
        return a;
    }
    ll x = binpow(a, b / 2);
    if (b % 2 == 0)
    {
        return (x % MOD * x % MOD) % MOD;
    }
    else
    {
        return (x % MOD * x % MOD * a % MOD) % MOD;
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    string n;
    cin >> n;
    string m = n;
    reverse(m.begin(), m.end());
    cout << binpow(stoll(n), stoll(m));
    return 0;
}