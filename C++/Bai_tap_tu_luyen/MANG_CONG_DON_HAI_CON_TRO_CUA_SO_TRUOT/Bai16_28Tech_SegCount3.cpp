#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long l = 0;
    long long ans = 0;
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
        if (mp[a[i]]==1)
        {
            cnt++;
        }
        while (cnt > s)
        {
            mp[a[l]]--;
            if (mp[a[l]] == 0)
            {
                cnt--;
            }
            l++;
        }
        ans += i - l + 1;
    }

    cout << ans;
}