#include <bits/stdc++.h>
using namespace std;

int p[1001];

int a[1000][1000];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    set<int> se;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[a[i][j]] == i - 1)
            {
                p[a[i][j]]++;
            }
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        if (p[i] == n)
        {
            se.insert(i);
        }
    }
    if (se.empty())
        cout << "NOT FOUND";
    else
        for (auto x : se)
        {
            cout << x << " ";
        }
}