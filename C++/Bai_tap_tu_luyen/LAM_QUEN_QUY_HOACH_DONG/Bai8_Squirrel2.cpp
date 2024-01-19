#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

ll f[1000001];

void solve_case(int n, int k, ll a[])
{
    f[0] = 0;
    for (int i = 1; i < n; i++)
    {
        f[i] = LLONG_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                f[i] = min(1ll * f[i], f[i - j] + abs(a[i] - a[i - j]));
            }
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solve_case(n, k, a);
    cout << f[n - 1] << endl;
    return 0;
}