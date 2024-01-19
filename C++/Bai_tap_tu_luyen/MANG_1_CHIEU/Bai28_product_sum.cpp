#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long res = 0;
    long long mod = 1000000007;
    for (int i = 0; i < n; i++)
    {
        res += (a[i] % mod * i % mod) % mod;
        res %= mod;
    }
    cout << res;
}