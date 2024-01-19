#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = MOD;
    long long sum = 0;
    long long l = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        while (sum >= m)
        {
            ans = min(ans, i - l + 1);
            sum -= a[l];
            l++;
        }
    }
    if (ans == MOD)
    {
        cout << -1;
    }
    else
        cout << ans;
}
