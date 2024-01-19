#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;

    cin >> n >> q;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long D[n];
    D[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        D[i] = a[i] - a[i - 1];
    }

    int l, r, k;
    while (q--)
    {
        cin >> l >> r >> k;
        D[l] += k;
        D[r + 1] -= k;
    }
    for (int i = 0; i < n; i++)
    {
        if (i==0)
            a[i] = D[i];
        else
            a[i] = D[i] + a[i - 1];
        cout << a[i] << " ";
    }
}