#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int Find(int a[], int n)
{
    int l = 0, r = n - 1;

    int index = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == 0)
        {
            l = m + 1;
            index = max(index, m);
        }
        else
        {
            r = m - 1;
        }
    }
    return index;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int index = Find(a, n);
    cout << index + 1 << endl;
    return 0;
}