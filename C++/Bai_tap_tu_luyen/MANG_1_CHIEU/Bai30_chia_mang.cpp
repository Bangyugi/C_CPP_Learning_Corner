#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long sum1 = 0, sum2 = 0;
    if (k <= n / 2)
    {
        sort(a, a + n);
        for (int i = 0; i < k; i++)
        {
            sum1 += a[i];
        }
        for (int i = k; i < n; i++)
        {
            sum2 += a[i];
        }
    }
    else
    {
        sort(a, a + n, greater<int>());
        for (int i = 0; i < k; i++)
        {
            sum1 += a[i];
        }
        for (int i = k; i < n; i++)
        {
            sum2 += a[i];
        }
    }
    cout << abs(sum1 - sum2);
}