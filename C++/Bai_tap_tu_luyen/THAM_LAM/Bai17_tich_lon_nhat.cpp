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
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    ll maxOfTwoValue = max(1ll * a[0] * a[1], 1ll * a[n - 1] * a[n - 2]);
    ll maxOfThreeValue = max({1ll * a[0] * a[1] * a[n - 1], 1ll * a[n - 1] * a[n - 2] * a[n - 3]});
    cout << max(maxOfTwoValue, maxOfThreeValue);
    return 0;
}