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

    set<int> se;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        se.insert(b[i]);
    }

    for (auto it = se.begin(); it != se.end(); it++)
    {
        if (mp[*it] == 0 || mp[*it] == 1)
        {
            mp[*it]++;
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if ((*it).second == 1)
        {
            cout << (*it).first << " ";
        }
    }
}
