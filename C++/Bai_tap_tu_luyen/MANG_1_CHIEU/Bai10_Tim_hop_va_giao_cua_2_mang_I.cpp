#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    map<int, int> mp;
    set<int> se;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        se.insert(a[i]);
        if (!mp.count(a[i]))
            mp[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        se.insert(b[i]);
        if (mp[b[i]] == 1)
            mp[b[i]]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if ((*it).second == 2)
            cout << (*it).first << " ";
    }
    cout << endl;
    for (auto it = se.begin(); it != se.end(); it++)
    {
        cout << *it << " ";
    }
}