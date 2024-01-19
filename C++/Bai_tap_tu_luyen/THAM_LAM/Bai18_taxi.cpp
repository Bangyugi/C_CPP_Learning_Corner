#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    int x[5] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        x[a[i]]++;
    }
    int ans = x[4] + x[2] / 2;
    x[2] %= 2;
    if (x[3] >= x[1])
    {
        ans += (x[3] + x[2]);
    }
    else
    {
        ans += x[3];
        int temp = x[1] - x[3];
        if (temp % 4 == 0)
        {
            ans += temp / 4 + x[2];
        }
        else if (temp % 4 <= 2)
        {
            ans += temp / 4 + 1;
        }
        else
        {
            ans += temp / 4 + 1 + x[2];
        }
    }
    cout << ans;
}