#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long F[n];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            F[i] = a[i];
        else
            F[i] = F[i - 1] + a[i];
    }
    int q;
    cin >> q;
    int l, r;
    while (q--)
    {
        cin >> l >> r;
        l--;
        r--;
        if (l == 0)
        {
            cout << F[r] << endl;
        }
        else
        {
            cout << F[r] - F[l - 1] << endl;
        }
    }
}