#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    long long cnt = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if ((*it).second >= 2)
        {
            cnt += ((long long)(*it).second * ((*it).second - 1)) / 2;
        }
    }
    cout << cnt;
}