#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long sum = 0;
    int ans = -1;
    map<long long, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        sum = (sum % k + k) % k;
        if (sum == 0)
        {
            ans = i + 1;
        }
        if (mp.count(sum))
        {
            ans = max(ans, i - mp[sum]);
        }
        if (mp.count(sum) == 0)
        {
            mp[sum] = i;
        }
    }
    cout << ans;
}