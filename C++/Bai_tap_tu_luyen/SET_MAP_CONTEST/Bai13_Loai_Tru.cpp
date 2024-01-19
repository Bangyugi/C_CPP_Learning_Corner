#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (mp[a[i]] == 0)
            mp[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        if (mp[b[i]] == 1)
            mp[b[i]]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if ((*it).second == 1)
        {
            cout << (*it).first << " ";
        }
    }
}
