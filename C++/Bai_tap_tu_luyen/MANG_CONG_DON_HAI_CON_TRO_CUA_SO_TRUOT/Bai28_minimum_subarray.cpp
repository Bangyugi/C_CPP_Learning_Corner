#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long sum = 0;
    int l = 0;
    int ans = INT_MAX;
    int index = l;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        while (sum >= k)
        {
            // ans = i - l + 1;
            if (i - l + 1 < ans)
            {
                ans = i - l + 1;
                index = l;
            }
            sum -= a[l];
            l++;
        }
    }
    if (ans == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        for (int i = index; i < ans + index; i++)
        {
            cout << a[i] << " ";
        }
    }
}