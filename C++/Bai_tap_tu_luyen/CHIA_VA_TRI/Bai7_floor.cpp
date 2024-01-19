#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int lowerBound(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    int res = -1;
    while (l <= r)
    {
        int m = (r + l) / 2;
        if (a[m] > x)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
            res = max(res, a[m]);
        }
    }
    return res;
}

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << lowerBound(a, n, x);
    return 0;
}