#include <bits/stdc++.h>
using namespace std;

int cnt[2];
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int sum = 0;
    int ans = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    if (sum == k)
    {
        cout << 0;
        return 0;
    }
    else
    {
        if ((k - sum) <= (cnt[1] - sum))
        {
            ans = min(ans, k - sum);
        }
    }
    for (int i = k; i < n; i++)
    {
        sum = sum + a[i] - a[i - k];
        if (sum == k)
        {
            cout << 0;
            return 0;
        }
        else
        {
            if ((k - sum) <= (cnt[1] - sum))
            {
                ans = min(ans, k - sum);
            }
        }
    }
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
}
