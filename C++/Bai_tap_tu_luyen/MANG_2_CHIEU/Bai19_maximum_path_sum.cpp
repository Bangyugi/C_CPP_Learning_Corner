#include <bits/stdc++.h>
using namespace std;

long long a[1000][1000];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = max(a[i][j] + a[i - 1][j], a[i][j] + a[i][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // for (int j = 1; j <= m; j++)
        // {
        //     cout << a[i][j] << " ";
        // }
        // cout << endl;
    }
    cout << a[n][m];
}