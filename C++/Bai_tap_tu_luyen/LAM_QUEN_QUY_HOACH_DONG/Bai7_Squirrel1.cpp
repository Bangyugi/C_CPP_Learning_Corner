#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

ll f[1000001];

void solve_case(int n, int a[])
{
    f[0] = 0;
    f[1] = f[0] + abs(a[1] - a[0]);
    for (int i = 2; i <= n; i++)
    {
        f[i] = min(f[i - 1] + abs(a[i] - a[i - 1]), f[i - 2] + abs(a[i] - a[i - 2]));
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solve_case(n, a);
    cout << f[n - 1] << endl;
    return 0;
}