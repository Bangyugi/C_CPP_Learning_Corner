#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

void solve_1(int n, vector<int> &v)
{
    if (n <= 1)
    {
        v.push_back(n);
    }
    else
    {
        solve_1(n / 2, v);
        v.push_back(n % 2);
        solve_1(n / 2, v);
    }
}
int main()
{
    vector<int> v;
    int n, l, r;
    cin >> n >> l >> r;
    solve_1(n, v);
    ll ans = 0;
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << ans;
    return 0;
}