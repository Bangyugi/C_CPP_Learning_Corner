#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int isPrime[1000001];
ll f[10000001];

void Sieve()
{
    for (int i = 2; i <= 1e6; i++)
    {
        isPrime[i] = 1;
    }
    for (int i = 2; i <= sqrt(1e6); i++)
    {
        if (isPrime[i] == 1)
        {
            for (int j = i * i; j <= 1e6; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    ll sum = 1;
    for (int i = 2; i <= 1e6; i++)
    {
        if (isPrime[i])
        {
            sum *= i % MOD;
            sum %= MOD;
        }
        f[i] = sum;
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    Sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}