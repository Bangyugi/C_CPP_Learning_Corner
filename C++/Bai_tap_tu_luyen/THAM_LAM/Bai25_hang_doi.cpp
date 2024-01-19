#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= sum)
        {
            sum += a[i];
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}