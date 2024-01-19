#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll max = 0;
    for (int i = 0; i < n; i++)
    {
        max += a[i] % MOD * i % MOD;
        max %= MOD;
    }
    cout << max << endl;
    return 0;
}