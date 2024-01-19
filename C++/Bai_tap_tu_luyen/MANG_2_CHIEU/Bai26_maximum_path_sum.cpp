#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

int main()
{
    int n;
    cin >> n;
    int max_val = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = max({a[i][j] + a[i - 1][j - 1], a[i][j] + a[i - 1][j], a[i][j] + a[i - 1][j + 1]});
            max_val = max(max_val, a[i][j]);
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << max_val;
}`