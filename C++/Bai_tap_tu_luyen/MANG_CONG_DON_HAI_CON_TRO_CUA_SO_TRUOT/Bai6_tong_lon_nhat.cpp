#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    int r, l;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int d[n + 1] = {0};
    while (q--)
    {
        cin >> l >> r;
        l--;
        r--;
        d[l] += 1;
        d[r + 1] -= 1;
    }

    int F[n];
    F[0] = d[0];
    for (int i = 1; i < n; i++)
    {
        F[i] = F[i - 1] + d[i];
    }
    sort(a, a + n, greater<int>());
    sort(F, F + n, greater<int>());
    long long res = 0;
    for (int i = 0; i < n;i++)
    {
        res += 1ll * a[i] * F[i];
    }
    cout << res << endl;
}