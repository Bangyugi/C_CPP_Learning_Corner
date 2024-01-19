#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

ll fibo[100];

void init()
{
    fibo[1] = 1;
    for (int i = 2; i < 92; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}

ll Lmao(ll n, ll k)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (k <= fibo[n - 2])
    {
        return Lmao(n - 2, k);
    }
    else
    {
        return Lmao(n - 1, k - fibo[n - 2]);
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    ll n;
    ll k;
    cin >> n >> k;
    init();
    cout << Lmao(n, k) << endl;
    return 0;
}