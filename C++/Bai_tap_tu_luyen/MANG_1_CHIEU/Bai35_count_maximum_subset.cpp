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
    sort(a, a + n);
    multiset<int> mse;
    int l = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        mse.insert(a[i]);
        while (*mse.rbegin() - *mse.begin() > k)
        {
            mse.erase(mse.find(a[l]));
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
}