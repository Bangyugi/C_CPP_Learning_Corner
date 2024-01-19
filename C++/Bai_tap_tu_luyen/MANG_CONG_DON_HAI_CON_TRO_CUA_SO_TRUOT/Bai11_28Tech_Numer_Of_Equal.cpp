#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    map<long long, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        ans += mp[b[i]];
    }
    cout << ans;
}
    