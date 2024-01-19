#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
ll f[1000001];

void run_case()
{
    f[0] = f[1] = 1;
    for (ll i = 2; i <= 1e6; i++)
    {
        f[i] = f[i - 1] * i;
        f[i] %= MOD;
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    run_case();
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