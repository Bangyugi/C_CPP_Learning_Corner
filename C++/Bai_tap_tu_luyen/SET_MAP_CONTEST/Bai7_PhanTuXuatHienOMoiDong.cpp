#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (mp[a[i][j]] == i)
                mp[a[i][j]]++;
        }
    }
    bool check = false;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if ((*it).second == n)
        {
            cout << (*it).first << " ";
            check = true;
        }
    }
    if (!check)
    {
        cout << "NOT FOUND";
    }
}