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
    int l = 0;
    map<int, int> mp;
    for (int i = 0; i <= k; i++)
    {
        mp[a[i]]++;
        if (mp[a[i]] == 2)
        {
            cout << "YES";
            return 0;
        }
    }
    for (int i = k + 1; i < n; i++)
    {
        mp[a[l++]]--;
        mp[a[i]]++;
        if (mp[a[i]] == 2)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}