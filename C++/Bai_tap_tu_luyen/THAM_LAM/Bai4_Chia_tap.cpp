#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    ll arr1 = min(k, n - k);
    ll arr2 = n - arr1;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll sum1 = 0;
    ll sum2 = 0;
    for (int i = 0; i < arr1; i++)
    {
        sum1 += a[i];
    }
    for (int i = arr1; i < arr1 + arr2; i++)
    {
        sum2 += a[i];
    }
    cout << sum2 - sum1;
    return 0;
}