#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int Find(int a[], int b[], int n)
{
    int l = 0, r = n - 1;
    int index = INT_MAX;
    while (l <= r)
    {
        int m = (l + r + 1) / 2;
        if (a[m] != b[m])
        {
            r = m - 1;
            index = min(index, m);
        }
        else
        {
            l = m + 1;
        }
    }
    return index;
}

int main()
{
    int n;
    cin >> n;
    int a[n], b[n - 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }
    int index = Find(a, b, n);
    cout << index + 1;

    return 0;
}